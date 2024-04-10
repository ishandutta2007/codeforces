//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 1E5+7;
int A[2][DIM];
void solve(){
    int n;
    cin>>n;
    for(int c = 0;c<2;++c) {
        for (int i = 1; i <= n; ++i) {
            cin >> A[c][i];
            A[c][i] += A[c][i - 1];
        }
        A[c][n+1] = A[c][n];
    }
    int res = 2E9+7;
    A[0][n+1] = A[0][n];
    for(int i = 1;i<=n+1;++i){
        int r = max(A[1][i-1],A[0][n]-A[0][i]);
        res = min(res,r);
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}