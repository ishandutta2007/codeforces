#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100000];
ll b[100000];
ll raz[100000];

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int k1, k2;
    cin >> k1 >> k2;
    ll k = k1+k2;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) raz[i] = abs(a[i]-b[i]);
    while(k--){
        ll maxraz = 0;
        for(int i=0; i<n; i++) maxraz = max(maxraz, raz[i]);
        if(maxraz == 0){raz[0]++; continue;}
        for(int i=0; i<n; i++) if(maxraz == raz[i]){raz[i]--; break;}
    }
    ll ukup=0;
    for(int i=0; i<n; i++){
        ukup += raz[i]*raz[i];
    }
    cout << ukup;
    return 0;
}