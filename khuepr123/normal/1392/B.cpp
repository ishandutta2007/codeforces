#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a[200012]; ll mx;

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin >> t; ll n, k;
    while(t--){
        cin >> n >> k;
        if(k > 0){
            k = k % 2;
            k = 2 - k;
        }
        for(ll j = 0; j < n; j++){
            cin >> a[j];
        }
        for(ll i = 0; i < k; i++){
            mx = a[0];
            for(ll j = 1; j < n; j++){
                if(mx < a[j]){
                    mx = a[j];
                }
            }
            for(ll j = 0; j < n; j++){
                a[j] = mx - a[j];
            }
        }
        for(ll j = 0; j < n; j++){
            cout << a[j] << " ";
        }
        cout << "\n";
    }
}