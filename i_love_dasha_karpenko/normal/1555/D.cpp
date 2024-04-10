//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 2E5+7;
int A[DIM],dp[6][DIM],nxt[6][3];
void solve(){
    int n,m;
    cin>>n>>m;
    nxt[0][0] = 0;
    nxt[0][1] = 1;
    nxt[0][2] = 2;
    for(int c = 1;c<6;++c){
        for(int e = 0;e<3;++e)
            nxt[c][e] = nxt[c-1][e];
        next_permutation(nxt[c],nxt[c]+3);
    }
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'a';
        for(int c = 0;c<6;++c){
            dp[c][i] = dp[c][i-1]+(nxt[c][i%3]!=A[i]);
        }
    }
    for(int i = 1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        int res = r-l+1;
        for(int c = 0;c<6;++c){
            res = min(res,dp[c][r]-dp[c][l-1]);
        }
        cout<<res<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
    return 0;
}