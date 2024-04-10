#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bitset <505> dp[505][505];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n, k;
    cin >> n >> k;
    dp[0][0][0] = 1;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        for(int j=0; j<=k; j++){
            dp[i][j] |= dp[i-1][j];
        }
        for(int j=x; j<=k; j++){
            dp[i][j] |= (dp[i-1][j-x] << x) | dp[i-1][j-x];
        }
    }
    queue <int> q;
    for(int i=0; i<=k; i++){
        if(dp[n][k][i]) q.push(i);
    }
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}