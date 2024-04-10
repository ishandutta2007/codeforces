#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define int long long
const ll mod = 998244353;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n; int ev[maxN]; int od[maxN];
int val[maxN];


int gcdExtended(int a, int b, int* x, int* y); 
  
// Function to find modulo inverse of a 
int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1;
    else 
    { 
        // m is added to handle negative x 
        int res = (x % m + m) % m; 
        return res;
    } 
} 
  
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int* x, int* y) 
{ 
    // Base Case 
    if (a == 0)  
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b % a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    val[1] = 1; val[2] = 1;
    for(int i = 3; i <= n; i++){
        val[i] = val[i - 1] + val[i - 2];
        val[i] = val[i] % mod;
    }
    int x = val[n]; int nn = n;
    int pw = 1; int nnnnn = 2;
    while(n--){
        pw *= nnnnn;
        pw = pw % mod;
    }
    pw = modInverse(pw, mod);
    cout << ((x * pw) % mod + mod) % mod;
}