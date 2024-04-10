#pragma GCC optimize "Ofast"
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
typedef pair<int,int> pi;
const int  oo = 1e9, masks=1<<12;
const int One = 1, Two = 3|(3<<4), Three = 7|(7<<4)|(7<<8), Four = masks-1;

pi last(int i, int j) {
    int id = i*4+j-11;
    if(id<0) return {-1,-1};
    return {id/4,id%4};
}

void cmin(int& a, int b) {a=min(a,b);}

int dp[2][4][masks];
char g[1000][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[5];
    for(int i=1;i<=4;++i) cin >> a[i];
    for(int j=0;j<4;++j) {
        for(int i=0;i<n;++i) cin >> g[i][j];
    }
    for(int i:{0,1}) for(int j=0;j<4;++j) fill(dp[i][j],dp[i][j]+masks,oo);
    dp[0][0][0]=0;
    for(int i=0;i<n+4;++i) {
        for(int j=0;j<4;++j) {
            auto [lasti,lastj] = last(i,j);
            bool bad = (lasti>=0 and lasti<n)?g[lasti][lastj]=='*':false;
            auto nxtrow = dp[(i+1)%2][j], cur = dp[i%2][j];
            auto nw = dp[(i+(j==3))%2][(j+1)%4];

            fill(nxtrow,nxtrow+masks,oo);
            for(int m=0;m<masks;++m) if(cur[m]!=oo) {
                auto ne = [&](int st) {return st<<1 & Four;};
                if(!bad or (m & masks/2)) {
                    cmin(nw[ne(m)], cur[m]);
                    cmin(nw[ne(m|One)],cur[m]+a[1]);
                    if(j>=1) cmin(nw[ne(m|Two)], cur[m]+a[2]);
                    if(j>=2) cmin(nw[ne(m|Three)], cur[m]+a[3]);
                }
                if(j==3) cmin(nxtrow[Four], cur[m]+a[4]);
            }
        }
    }
    cout << *min_element(dp[n%2][0],dp[n%2][0]+masks) << '\n';

}