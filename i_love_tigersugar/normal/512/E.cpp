#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
vector<pair<int,int> > allModify;
class Polygon {
    private:
    int n;
    vector<int> label;
    vector<set<int> > adj;
    void splitPolygon(Polygon &a,Polygon &b,int x,int y) const {
        if (x>y) return (splitPolygon(a,b,y,x));
        FOR(i,x,y) a.label.push_back(label[i]);
        FOR(i,0,x) b.label.push_back(label[i]);
        FOR(i,y,n-1) b.label.push_back(label[i]);
        a.n=a.label.size();
        b.n=b.label.size();
        a.adj.assign(a.n,set<int>());
        b.adj.assign(b.n,set<int>());
        REP(i,n) FORE(it,adj[i]) {
            int j=*it;
            Polygon &cur=(x<=i && i<=y && x<=j && j<=y)?a:b;
            int idi=lower_bound(cur.label.begin(),cur.label.end(),label[i])-cur.label.begin();
            int idj=lower_bound(cur.label.begin(),cur.label.end(),label[j])-cur.label.begin();
            cur.adj[idi].insert(idj);
            cur.adj[idj].insert(idi);
        }
        int idx,idy;
        idx=lower_bound(a.label.begin(),a.label.end(),label[x])-a.label.begin();
        idy=lower_bound(a.label.begin(),a.label.end(),label[y])-a.label.begin();
        a.adj[idx].insert(idy);
        a.adj[idy].insert(idx);
        idx=lower_bound(b.label.begin(),b.label.end(),label[x])-b.label.begin();
        idy=lower_bound(b.label.begin(),b.label.end(),label[y])-b.label.begin();
        b.adj[idx].insert(idy);
        b.adj[idy].insert(idx);
    }
    int prevInSet(const set<int> &s,set<int>::iterator it) const {
        if (it==s.begin()) it=s.end();
        it--;
        return (*it);
    }
    int nextInSet(const set<int> &s,set<int>::iterator it) const {
        it++;
        if (it==s.end()) it=s.begin();
        return (*it);
    }
    bool haveEdge(int i,int j) const {
        return (adj[i].find(j)!=adj[i].end());
    }
    pair<int,int> tryChange(int i,set<int>::iterator it) const {
        int x=prevInSet(adj[i],it);
        int y=nextInSet(adj[i],it);
        return (make_pair(x,y));
    }
    void fixChange(int u,int v,int x,int y) {
        adj[u].erase(v);
        adj[v].erase(u);
        adj[x].insert(y);
        adj[y].insert(x);
        allModify.push_back(make_pair(label[u],label[v]));
        /*printf("after change %d %d to %d %d\n",u,v,x,y);
        debug();*/
    }
    void debug(void) const {
        printf("POLYGON of %d\n",n);
        printf("LABEL: ");
        REP(i,n) printf("%d ",label[i]);
        printf("\n");
        REP(i,n) {
            printf("adj of %d: ",i);
            FORE(it,adj[i]) printf("%d ",*it);
            printf("\n");
        }
        printf("___END___\n");
    }
    public:
    Polygon() {
        n=0;
    }
    Polygon(int n) {
        this->n=n;
        REP(i,n) label.push_back(i+1);
        adj.assign(n,set<int>());
        REP(i,n) {
            adj[i].insert((i+1+n)%n);
            adj[i].insert((i-1+n)%n);
        }
    }
    void input(void) {
        REP(love,n-3) {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;y--;
            adj[x].insert(y);
            adj[y].insert(x);
        }
    }
    void modify(const Polygon &goal) {
        if (n<4) return;
        /*printf("Modify:\n");
        debug();
        printf("TO\n");
        goal.debug();*/
        REP(i,n) FORE(it,adj[i]) if (*it!=(i+1)%n && *it!=(i-1+n)%n && goal.haveEdge(i,*it)) {
            int j=*it;
            //printf("same edge found %d %d\n",i,j);
            Polygon A,B,goalA,goalB;
            splitPolygon(A,B,i,j);
            goal.splitPolygon(goalA,goalB,i,j);
            A.modify(goalA);
            B.modify(goalB);
            return;
        }
        REP(i,n) FORE(it,adj[i]) if (*it!=(i+1)%n && *it!=(i-1+n)%n) {
            pair<int,int> tmp=tryChange(i,it);
            if (goal.haveEdge(tmp.fi,tmp.se)) {
                int j=*it;
                fixChange(i,j,tmp.fi,tmp.se);
                //printf("single change %d %d to %d %d\n",i,j,tmp.fi,tmp.se);
                Polygon A,B,goalA,goalB;
                splitPolygon(A,B,tmp.fi,tmp.se);
                goal.splitPolygon(goalA,goalB,tmp.fi,tmp.se);
                A.modify(goalA);
                B.modify(goalB);
                return;
            }
        }
        int chs=-1;
        REP(i,n) if (goal.adj[i].size()<3)
            if (chs<0 || adj[i].size()<adj[chs].size()) chs=i;
        int u=chs;
        int x=(u-1+n)%n;
        int y=(u+1+n)%n;
        //printf("Fix triangle %d %d %d\n",u,x,y);
        while (adj[u].size()>2) {
            FORE(it,adj[u]) if (*it!=x && *it!=y) {
                pair<int,int> tmp=tryChange(u,it);
                fixChange(u,*it,tmp.fi,tmp.se);
                break;
            }
        }
        Polygon A,B,goalA,goalB;
        splitPolygon(A,B,x,y);
        goal.splitPolygon(goalA,goalB,x,y);
        A.modify(goalA);
        B.modify(goalB);
    }
};
void process(void) {
    int n;
    scanf("%d",&n);
    Polygon src(n),des(n);
    src.input();
    des.input();
    src.modify(des);
    printf("%d\n",(int)allModify.size());
    FORE(it,allModify) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    process();
    return 0;
}