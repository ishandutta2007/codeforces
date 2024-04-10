/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// only when really needed

/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define sz(a) (int)a.size()
#define pii pair<int,int>
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD2 1000000009
#define EPS 1e-6

using namespace std;

int gcd(int a, int b) {
    
    if (b == 0) return a;
    return gcd(b, a % b);
    
}

int lcm(int a, int b) { return a * b / gcd(a, b); };

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        
        int n, k;
        cin >> n >> k;
        while(k != 3){
            k--;
            n--;
            cout << 1 << " ";
        }
        
        if (n & 1) cout << n/2 << " " << n/2 << " " << 1 << "\n";
        else {
            
            int r = n/2 - 1;
            while (lcm(r, n - r*2) > n/2) {
                r--;
            }
            
            cout << r << " " << r << " " << n - r*2 << "\n";
            
        }
        
    }
    
}