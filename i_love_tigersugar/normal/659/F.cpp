#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
class DisjointSet {
    private:
    vector<int> lab;
    int find(int x) {
        return (lab[x]<0?x:lab[x]=find(lab[x]));
    }
    public:
    DisjointSet(){}
    DisjointSet(int n) {
        lab.assign(n+7,-1);
    }
    int join(int x,int y) {
        x=find(x);
        y=find(y);
        if (x==y) return (-lab[x]);
        if (lab[x]>lab[y]) swap(x,y);
        lab[x]+=lab[y];
        lab[y]=x;
        return (-lab[x]);
    }
    int getSize(int x) {
        return (-lab[find(x)]);
    }
};
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const string yes="YES";
const string no="NO";
int m,n,a[MAX][MAX],pos[MAX][MAX];
bool vst[MAX][MAX],added[MAX][MAX];
long long sum;
vector<pair<int,int> > cell;
DisjointSet dsu;
bool Comp(const pair<int,int> &p,const pair<int,int> &q) {
    return (a[p.fi][p.se]<a[q.fi][q.se]);
}
void init(void) {
    cin>>m>>n>>sum;
    FOR(i,1,m) FOR(j,1,n) cin>>a[i][j];
    FOR(i,1,m) FOR(j,1,n) cell.push_back(make_pair(i,j));
    int tmp=0;
    FOR(i,1,m) FOR(j,1,n) pos[i][j]=++tmp;
    sort(ALL(cell),Comp);
    dsu=DisjointSet(m*n);
}
bool inside(int x,int y) {
    if (x<1 || x>m || y<1 || y>n) return (false);
    return (true);
}
bool ok(long long lim) {
    while (!cell.empty()) {
        int x=cell.back().fi;
        int y=cell.back().se;
        if (a[x][y]<lim) return (false);
        added[x][y]=true;
        if (sum==lim && a[x][y]==lim) return (true);
        cell.pop_back();
        REP(i,4) if (inside(x+dx[i],y+dy[i])) {
            int u=x+dx[i];
            int v=y+dy[i];
            if (!added[u][v]) continue;
            if (dsu.join(pos[u][v],pos[x][y])>=sum/lim && a[x][y]==lim) return (true);
        }
    }
    return (false);
}
void myAssert(bool a) {
    while (!a) cout<<"FUCK"<<endl;
}
void bfs(int x,int y,int num) {
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    vst[x][y]=true;
    int cnt=1;
    while (!q.empty() && cnt<num) {
        int ux=q.front().fi;
        int uy=q.front().se;
        q.pop();
        REP(i,4) if (inside(ux+dx[i],uy+dy[i])) {
            int vx=ux+dx[i];
            int vy=uy+dy[i];
            if (added[vx][vy] && !vst[vx][vy]) {
                if (cnt<num) {
                    cnt++;
                    vst[vx][vy]=true;
                    q.push(make_pair(vx,vy));
                }
            }
        }
    }
    myAssert(cnt==num);
    cout<<yes<<endl;
    int cntCell=0;
    bool ok=false;
    FOR(i,1,m) {
        FOR(j,1,n) {
            long long tmp=vst[i][j]?sum/num:0LL;
            myAssert(tmp<=a[i][j]);
            cout<<tmp<<" ";
            if (tmp>0) cntCell++;
            if (tmp==a[i][j]) ok=true;
        }
        cout<<"\n";
    }
    myAssert(ok && sum%num==0 && 1LL*cntCell*(sum/num)==sum);
    exit(0);
}
void process(void) {
    FOR(k,1,m*n) if (sum%k==0 && ok(sum/k)) {
        FOR(i,1,m) FOR(j,1,n) if (a[i][j]==sum/k && added[i][j] && dsu.getSize(pos[i][j])>=k)
            return (bfs(i,j,k));
        assert(false);
    }
    cout<<no<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}