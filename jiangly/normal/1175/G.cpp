#include<bits/stdc++.h>
using namespace std;
using LL=long long;
constexpr int MAX_N=2e4+5;
constexpr int INF=1e9;
int n,k;
LL a[MAX_N];
class Point{
public:
    LL x;
    LL y;
    Point():x(0),y(0){}
    Point(LL x,LL y):x(x),y(y){}
};
Point operator + (const Point &a,const Point &b){
    return {a.x+b.x,a.y+b.y};
}
Point operator - (const Point &a,const Point &b){
    return {a.x-b.x,a.y-b.y};
}
LL dot(const Point &a,const Point &b){
    return a.x*b.x+a.y*b.y;
}
LL cross(const Point &a,const Point &b){
    return a.x*b.y-b.x*a.y;
}
Point rotate(const Point &a){
    return {-a.y,a.x};
}
class ConvexHull{
public:
    deque<Point> pts,vecs;
    void insertRight(const Point &p){
        while(!vecs.empty()&&dot(vecs.back(),p-pts.back())<0){
            pts.pop_back();
            vecs.pop_back();
        }
        if(!pts.empty()){
            vecs.push_back(rotate(p-pts.back()));
        }
        pts.push_back(p);
    }
    void insertLeft(const Point &p){
        while(!vecs.empty()&&dot(vecs.front(),p-pts.front())<0){
            pts.pop_front();
            vecs.pop_front();
        }
        if(!pts.empty()){
            vecs.push_front(rotate(pts.front()-p));
        }
        pts.push_front(p);
    }
    LL queryMin(const Point &p){
        auto it=lower_bound(vecs.begin(),vecs.end(),p,[](const Point &a,const Point &b){
            return cross(a,b)>0;
        });
        return dot(p,pts[it-vecs.begin()]);
    }
};
using pHull=unique_ptr<ConvexHull>;
void mergeHulls(pHull &a,pHull &b){
    if(a->pts.size()>=b->pts.size()){
        for(auto &p:b->pts){
            a->insertRight(p);
        }
        swap(a,b);
    }else{
        for(auto it=a->pts.rbegin();it!=a->pts.rend();++it){
            b->insertLeft(*it);
        }
    }
}
constexpr int M=1e6;
class Node{
public:
    Point line;
    Node *lc,*rc;
    Node():line(),lc(nullptr),rc(nullptr){}
    Node(Point line,Node *lc,Node *rc):line(move(line)),lc(lc),rc(rc){}
};
using Tree=Node *;
int cnt_node;
Node node[M];
Tree newNode(const Point &line,Tree lc,Tree rc){
    node[cnt_node]=Node(line,lc,rc);
    return &node[cnt_node++];
}
Tree newNode(Tree p){
    if(p==nullptr){
        return p;
    }else{
        return newNode(p->line,p->lc,p->rc);
    }
}
LL f(const Point &line,LL x){
    return dot(line,Point(x,1));
}
Tree insertLine(Tree p,int l,int r,Point line){
    if(p==nullptr){
        return newNode(line,nullptr,nullptr);
    }
    int mid=(l+r)/2;
    bool lf=f(line,l)<f(p->line,l);
    bool md=f(line,mid)<f(p->line,mid);
    if(md){
        swap(line,p->line);
    }
    if(l+1==r){
        return p;
    }else if(lf!=md){
        p->lc=insertLine(newNode(p->lc),l,mid,line);
    }else{
        p->rc=insertLine(newNode(p->rc),mid,r,line);
    }
    return p;
}
LL queryMin(Tree p,int l,int r,int x){
    if(p==nullptr){
        return INF;
    }
    if(l+1==r){
        return f(p->line,x);
    }
    int mid=(l+r)/2;
    if(x<mid){
        return min(f(p->line,x),queryMin(p->lc,l,mid,x));
    }else{
        return min(f(p->line,x),queryMin(p->rc,mid,r,x));
    }
}
class State{
public:
    int pos;
    pHull hull;
    Tree p;
    State():pos(-1),hull(nullptr),p(nullptr){}
};
LL dp[2][MAX_N]; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=0;i<=n-1;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        dp[0][i]=INF;
    }
    int cur=0;
    for(int step=1;step<=k;++step){
        cnt_node=0;
        cur^=1;
        stack<State> stk;
        for(int i=0;i<=n;++i){
            dp[cur][i]=INF;
            if(!stk.empty()){
                dp[cur][i]=queryMin(stk.top().p,0,n+1,i);
            }
            if(i==n){
                continue;
            }
            State now;
            now.pos=i;
            now.hull=make_unique<ConvexHull>();
            now.hull->insertRight({i,dp[cur^1][i]});
            while(!stk.empty()&&a[stk.top().pos]<a[i]){
                mergeHulls(stk.top().hull,now.hull);
                stk.pop();
            }
            if(!stk.empty()){
                now.p=stk.top().p;
            }
            LL val=now.hull->queryMin({-a[i],1});
            now.p=insertLine(newNode(now.p),0,n+1,{a[i],val});
            stk.push(move(now));
        }
    }
    cout<<dp[cur][n]<<endl;
    return 0;
}