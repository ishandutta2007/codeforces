#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l[305];
ll c[305];
ll dp[1000];

const ll INF = 10000000000000LL;

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> l[i];
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    ll res = INF;
    for(int i=1; i<=n; i++){
        int x = l[i];
        vector <int> vec;
        for(int j=2; j*j<=x; j++){
            if(x%j == 0){
                vec.push_back(j);
                while(x%j == 0) x /= j;
            }
        }
        if(x > 1) vec.push_back(x);
        int b = vec.size();
        int p = (1 << b) - 1;
        for(int j=p; j>=0; j--) dp[j] = INF;
        dp[0] = c[i];
        for(int j=0; j<=p; j++){
            for(int k=1; k<=n; k++){
                int e = j;
                for(int z=0; z<b; z++){
                    if(l[k]%vec[z]) e = e | (1 << z);
                }
                dp[e] = min(dp[e], dp[j] + c[k]);
            }
        }
        res = min(res, dp[p]);
    }
    if(res == INF) cout << -1;
    else cout << res;
    return 0;
}