#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll a[200012], h; bool x;

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin >> t; ll n;
    while(t--){
        cin >> n; cin >> h; x = 0;
        for(ll i = 2; i <= n; i++){
            cin >> a[i];
            if(h != a[i]){
                x = 1;
            }
        }
        if(x){
            cout << 1;
        }
        else{
            cout << n;
        }
        cout << "\n";
    }
    
}