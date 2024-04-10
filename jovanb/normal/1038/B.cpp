#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    ll n;
    cin >> n;
    ll x = n*(n+1)/2;
    for(ll i=2; i<=n; i++){
        if(x%i == 0){
            cout << "Yes\n";
            int br=0;
            for(int j=i; j<=n; j+=i) br++;
            int br2 = n-br;
            cout << br << " ";
            for(int j=i; j<=n; j+=i) cout << j << " ";
            cout << "\n" << br2 << " ";
            for(int j=1; j<=n; j++){
                if(j%i) cout << j << " ";
            }
            return 0;
        }
    }
    cout << "No";
    return 0;
}