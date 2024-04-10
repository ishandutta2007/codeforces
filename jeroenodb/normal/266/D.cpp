#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 200+1, oo = 1e9;
typedef array<int,3> edge;
int dist[mxN][mxN];
int main() {
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) {
        fill(dist[i],dist[i]+n,oo);
        dist[i][i]=0;
    }
    vector<edge> es(m);
    for(auto& [a,b,w] : es) {
        cin >> a >> b >> w,--a,--b;
        dist[a][b]=w;
        dist[b][a]=w;
    }
    for(int j=0;j<n;++j) {
        for(int i=0;i<n;++i) {
            for(int k=0;k<n;++k) {
                dist[i][k] = min(dist[i][k],dist[i][j]+dist[j][k]);
            }
        }
    }
    double ans = oo;
    for(auto& [a,b,w]: es) {
        vector<pi> s;
        int mxa=-oo,mxb=-oo;
        for(int i=0;i<n;++i) {
            int x = min(2*w,max(0,w+dist[b][i]-dist[a][i]));
            auto y = min(2*w-x+2*dist[b][i],x+2*dist[a][i]);
            s.push_back({x,y});
            mxa=max(dist[a][i],mxa);
            mxb=max(dist[b][i],mxb);
        }
        ans = min({ans,(double)mxa,(double)mxb});
        sort(all(s));
        vector<pi> hull;
        for(auto [x,y]: s) {
            if(!hull.empty() and hull.back().first+hull.back().second>=x+y and -hull.back().first+hull.back().second>=-x+y) continue;
            while(!hull.empty() and hull.back().first+hull.back().second<=x+y and -hull.back().first+hull.back().second<=-x+y) {
                hull.pop_back();
            }
            hull.push_back({x,y});
        }
        for(int i=1;i<(int)hull.size();++i) {
            // calc minimum
            auto [x,y] = hull[i-1];
            auto [c,d] = hull[i];
            ans = min(ans,0.25*(x+y-c+d));
        }
    }
    cout << ans << '\n';
}