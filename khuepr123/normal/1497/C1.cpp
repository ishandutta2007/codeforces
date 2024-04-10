#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;

int gcd(int a, int b) {
    
    if (b == 0) return a;
    return gcd(b, a % b);
    
}

int lcm(int a, int b) { return a * b / gcd(a, b); };


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        int n, k;
        cin >> n >> k;
        if (n % 2 == 1) cout << 1 << " " << n/2 << " " << n/2 << "\n";
        else {
            int wat = n/2 - 1;
            while (lcm(wat, n - wat*2) > n/2) {
                wat--;
            }
            
            cout << wat << " " << wat << " " << n - wat*2 << "\n";
            
        }
    }
}