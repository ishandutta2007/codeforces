#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        vi v(N);
        for(auto &x: v)cin >> x;
        vi dp(N+1,100000000);
        vi f(N+1,100000000);
    //    dp[0] = 0;
        f[0] = 0;
        for(int i = 0; i < N; i++){
            dp[i+1]=min(dp[i+1],f[i]+v[i]);
            f[i+1]=min(dp[i],f[i+1]);
            if(i > N-2)continue;
            dp[i+2]=min(dp[i+2],f[i]+v[i]+v[i+1]);
            f[i+2]=min(dp[i],f[i+2]);
        }
    /*    for(auto x: dp)cout << x << " ";
        cout << "\n";
        for(auto x: f)cout << x << " ";
        cout << "\n";
        */
        cout << min(dp[N],f[N])<<"\n";

    }

    return 0;
}