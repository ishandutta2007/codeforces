#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 57;
int A[N],dp[N][N];
void solve(){

    int n;
    cin>>n;
    vector<int> V;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
        if (A[i]==2)
            V.push_back(i);
    }
    if (V.size()<=2 && V.size()!=0){
        cout<<"NO\n";
        return;
    }
    memset(dp,0,sizeof(dp));
    for(int i = ll(V.size())-1;i>0;--i){
        dp[V[i]][V[i-1]] = 1;
        dp[V[i-1]][V[i]] = 2;
    }
    if (!V.empty()){
        dp[V.back()][V[0]] = 2;
        dp[V[0]][V.back()] = 1;
    }
    cout<<"YES\n";
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if (i==j){
                cout<<"X";
                continue;
            }
            if (dp[i][j]==0)
                cout<<'=';
            if (dp[i][j]==1)
                cout<<'+';
            if (dp[i][j]==2)
                cout<<'-';
        }
        cout<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}