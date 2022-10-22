#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5][2], b[N+5][2];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i][0];
    for(int i=1; i<=n; i++) cin >> a[i][1];
    for(int i=1; i<=n; i++) cin >> b[i][0];
    for(int i=1; i<=n; i++) cin >> b[i][1];
    ll res = 0, c0 = 0, c1 = 0;
    for(int i=1; i<=n; i++){
        if(a[i][0] && b[i][0]){
            a[i][0] = 0, b[i][0] = 0;
        }
        if(a[i][1] && b[i][1]){
            a[i][1] = 0, b[i][1] = 0;
        }
        if(c0 > 0 && a[i][0]){
            a[i][0] = 0;
            res += i;
            c0--;
        }
        if(c1 > 0 && a[i][1]){
            a[i][1] = 0;
            res += i;
            c1--;
        }
        if(c1 > 0 && a[i][0]){
            a[i][0] = 0;
            res += i + 1;
            c1--;
        }
        if(c0 > 0 && a[i][1]){
            a[i][1] = 0;
            res += i + 1;
            c0--;
        }
        if(c0 < 0 && b[i][0]){
            b[i][0] = 0;
            res += i;
            c0++;
        }
        if(c1 < 0 && b[i][1]){
            b[i][1] = 0;
            res += i;
            c1++;
        }
        if(a[i][0] && b[i][1]){
            a[i][0] = b[i][1] = 0;
            res++;
        }
        if(a[i][1] && b[i][0]){
            a[i][1] = b[i][0] = 0;
            res++;
        }
        if(c1 < 0 && b[i][0]){
            b[i][0] = 0;
            res += i + 1;
            c1++;
        }
        if(c0 < 0 && b[i][1]){
            b[i][1] = 0;
            res += i + 1;
            c0++;
        }
        if(a[i][0]){
            res -= i;
            c0--;
        }
        if(a[i][1]){
            res -= i;
            c1--;
        }
        if(b[i][0]){
            res -= i;
            c0++;
        }
        if(b[i][1]){
            res -= i;
            c1++;
        }
    }
    if(c0 || c1) cout << "-1\n";
    else cout << res << "\n";
    return 0;
}