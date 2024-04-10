#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
using namespace std;
const int mxN = 5e5+1;
vector<vector<int>> adj;
bitset<mxN> visited, blt,bad;
vector<int> groupid,comp;
void maketeams(int at, int cc, bool blue) {
    blt[at] = blue;
    comp[at] = cc;
    visited[at] = true;
    for(int to:adj[at]) {
        if(visited[to]) {
            if(blt[to] == blt[at]) {
                bad[groupid[at]] = true;
            }
        } else maketeams(to,cc,!blue);
    }
}

int main() {
    int n,m,k; cin >> n >> m >> k;
    groupid.resize(n);
    for(int i=0;i<n;++i) {
        cin >> groupid[i];
    }
    adj.resize(n);
    vector<pair<int,int>> intraedges;
    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b;
        --a;--b;
        if(groupid[a]>groupid[b]) swap(a,b);
        if(groupid[a]!=groupid[b]) {
            intraedges.push_back({a,b});
        } else {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    int count=1;
    comp.resize(n);
    for(int i=0;i<n;++i) {
        if(!visited[i]) {
            maketeams(i,count++,true);
        }
    }
    long long good = k-bad.count();
    long long ans = (good*(good-1))/2;
    sort(intraedges.begin(),intraedges.end(), [&](pair<int,int>& a, pair<int,int>& b) {
        return (pair<int,int>{groupid[a.first],groupid[a.second]} < pair<int,int>{groupid[b.first],groupid[b.second]});
    });
    pair<int,int> prev = {0,0};
    bool alsobad = false;
    struct DSU {
        bitset<mxN> flip;
        vector<int> rank, par;
        vector<int> changed;
        DSU(int n) {
            rank.resize(n); par.resize(n);
            fill(rank.begin(),rank.end(),1);
            for(int i=0;i<n;++i) {
                par[i] = i;
            }
        }
        int Find(int a) {
            bool flipped = false;
            while(a!=par[a]) {
                flipped^=flip[a];
                a = par[a];
            }
            return flipped?-a:a;
        }
        void Link(int a, int b,bool flipped) {
            if(rank[a]<rank[b]) swap(a,b);
            flip[b] = flipped;
            rank[a]=max(rank[a],rank[b]+1);
            par[b] = a;
            changed.push_back(a);
            changed.push_back(b);
        }
        void clear() {
            for(int i:changed) {
                par[i] = i;
                rank[i] = 1;
                flip[i]= false;
            }
            changed.clear();
        }
    };
    DSU dsu(n+1);


    for ( auto p : intraedges) {
        int i, j;
        tie(i,j) = p;
        int gr1 = groupid[i];
        int gr2 = groupid[j];
        if(bad[gr1] or bad[gr2]) continue;
        if(pair<int,int>{gr1,gr2}!=prev) {
            dsu.clear();
            ans-=alsobad;
            alsobad=false;
        }
        bool flip = blt[i]==blt[j];
        int c1 = comp[i],c2 = comp[j];
        int pa = dsu.Find(c1), pb= dsu.Find(c2);
        bool fa=pa>0, fb = pb>0;
        pa = abs(pa), pb = abs(pb);
        if(pa==pb){
            if((fa^fb)!=flip) alsobad = true;
        } else {
            dsu.Link(pa,pb, flip^fa^fb);
        }
        prev = {gr1,gr2};
    }
    cout << ans-alsobad << endl;
    
    
}