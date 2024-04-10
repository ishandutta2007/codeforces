#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define ick cout<<"ickbmi32.9\n"
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    bool yes[n + 5];
    for(int i = 1; i < n; i++) yes[i] = (__gcd(i, n) == 1);
    int prod = 1;
    int cnt = 0;
    for(int i = 1; i < n; i++) if(yes[i]) prod = prod * i % n, cnt++;
    int t = 1;
    for(int i = 1; i < cnt; i++) t = t * prod % n;
    cout << cnt - (t != 1) << '\n';
    for(int i = 1; i < n; i++) if((i != t || i == 1) && yes[i]) cout << i << ' ';
    cout << '\n';
    return 0;
}