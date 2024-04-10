#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1000000;

ll soln[N+5];

int a[N+5], b[N+5], c[N+5], change[N+5];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    b[1] = 1;
    for(int i=1; i<=n; i++) b[i] -= a[i];
    for(int i=1; i<=n; i++) a[i] = b[i];
    ll res = 0;
    for(int i=1; i<=n; i++){
        b[i] = a[i];
        res += abs(b[i]);
        for(int j=i; j<=n; j+=i) a[j] -= b[i];
    }
    c[1] = 1;
    for(int i=2; i<=n; i++) a[i] = 0;
    ll dif = 0;
    a[1] = -1;
    for(int i=1; i<=n; i++){
        c[i] = -a[i];
        if(c[i] == 1){
            if(b[i] < 0){
                change[0]--;
                if(-b[i] <= N) change[-b[i]] += 2;
            }
            else change[0]++;
        }
        if(c[i] == -1){
            if(b[i] > 0){
                change[0]--;
                if(b[i] <= N) change[b[i]] += 2;
            }
            else change[0]++;
        }
        for(int j=i; j<=n; j+=i) a[j] += c[i];
    }
    for(int i=0; i<1000000; i++){
        res += dif;
        soln[i+1] = res;
        dif += change[i];
    }
    int qrs;
    cin >> qrs;
    while(qrs--){
        int x;
        cin >> x;
        cout << soln[x] << "\n";
    }
    return 0;
}