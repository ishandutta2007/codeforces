#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll a[300005];
ll b[300005];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll s=0;
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        s += a[i];
    }
    int m;
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> b[i];
        s -= b[i];
    }
    if(s != 0){cout << -1; return 0;}
    ll l1=1, l2=1;
    ll s1=a[1], s2=b[1];
    ll res=0;
    while(l1 <= n && l2 <= m){
        if(s1 == s2){l1++; l2++; res++; s1 = a[l1]; s2 = b[l2];}
        else if(s1 < s2){l1++; s1 += a[l1];}
        else {l2++; s2 += b[l2];}
    }
    cout << res;
    return 0;
}