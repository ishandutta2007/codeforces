#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int dv[10000005];
const int N = 10000000;

int a[500005];
int d1[500005];
int d2[500005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    for(int i=2; i<=N; i++){
        if(!dv[i]){
            dv[i] = i;
            for(ll j=1LL*i*i; j<=N; j+=i){
                if(!dv[j]) dv[j] = i;
            }
        }
    }
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(!dv[a[i]]){
            d1[i] = d2[i] = -1;
            continue;
        }
        d1[i] = 1;
        int x = dv[a[i]];
        while(a[i]%x == 0){
            d1[i] *= x;
            a[i] /= x;
        }
        if(a[i] > 1) d2[i] = a[i];
        else d1[i] = d2[i] = -1;
    }
    for(int i=1; i<=n; i++) cout << d1[i] << " ";
    cout << "\n";
    for(int i=1; i<=n; i++) cout << d2[i] << " ";
    return 0;
}