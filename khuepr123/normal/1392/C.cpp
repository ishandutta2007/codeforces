#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a[200012]; ll sum;

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin >> t; ll n;
    while(t--){
        cin >> n; sum = 0;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(ll i = 2; i <= n; i++){
            if(a[i] < a[i - 1]){
                sum = sum + a[i - 1] - a[i];
            }
        }
        cout << sum << "\n";
    }
}