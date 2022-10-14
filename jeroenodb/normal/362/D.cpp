#include <iostream>
#include <queue>


using namespace std;
#define D(a) \
    do { cout << #a " " << (a) << std::endl; } while(false)
const int mxN = 1e5+2;
int n,m,p,q,par[mxN],sz[mxN];
long long rs[mxN]={};
int Find(int x) {
    if(par[x]==x) return x;
    return par[x]=Find(par[x]);
}
int Union(int x,int y,int l) {
    int px=Find(x),py=Find(y);
    if(px==py) {
        rs[px]+=l;
        return px;
    }
    if(sz[px]<sz[py]) swap(px,py);
    par[py]=px;
    sz[px]+=sz[py];
    rs[px]+=rs[py]+l;
    return px;
}
struct comp {
    bool operator()(int a,int b) {
        return rs[a]>rs[b];
    }
};

int main() {

    cin >> n >> m >> p >> q;
    for(int i=0;i<n;++i) {
        par[i]=i;
        sz[i]=1;
    }
    for(int i=0;i<m;++i) {
        int x,y,l;
        cin >> x >> y >> l;x--;y--;
        Union(x,y,l);
    }
    priority_queue<int,vector<int>,comp> pq;
    int dummya=-1, dummyb;
    for(int i=0;i<n;++i) {
        if(par[i]==i) {
            pq.push(i);
        } else if(dummya==-1) {
            dummya=i;
            dummyb = Find(dummya);
        }
    }
    int cn = pq.size();
    if(cn<q or cn-p>q) {
        cout << "NO\n";
        exit(0);
    } 
    vector<pair<int,int>> ans;
    int roadsleft = p;
    int x,y;
    for(int i=0;i<cn-q;++i) {
        roadsleft--;
        x = pq.top();pq.pop();
        y = pq.top();pq.pop();
        int l = min((long long)1e9,rs[x]+rs[y]+1);
        ans.push_back({x,y});
        pq.push(Union(x,y,l));
        dummya=x;dummyb=y;
    }
    if(roadsleft and dummya==-1) {
            cout << "NO\n";
            exit(0);
    }
    while(roadsleft--) {

        ans.push_back({dummya,dummyb});
    }
    cout << "YES\n";
    for(auto p: ans) {
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
    //cin >> n;
}