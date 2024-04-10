#include<bits/stdc++.h>
#define int long long
#define maxn 100005
using namespace std;

int n, k, a[maxn];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    a[0] = 1000000007;
    cin >> n >> k;
    a[k+1] = 1000000007;

    for(int i=1; i<=k; i++)
        a[i] = i, n -= i;

    if( n < 0 ){ cout << "NO"; return 0; }

    int upd = n / k;

    for(int i=1; i<=k; i++)
        a[i] += upd, n -= upd;

  for(int t=1; t<=100; t++)
    for(int i=k; i>=1; i--){
        while( n && a[i] + 1 <= 2 * a[i-1] && a[i] + 1 < a[i+1] ){ a[i]++, n--; }
    }

    if( n != 0 ){ cout << "NO"; return 0; }

    cout << "YES\n";
    for(int i=1; i<=k; i++){
        cout << a[i];
        if( i < k ) cout << ' ';
            else cout << '\n';
    }

    return 0;
}