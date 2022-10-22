#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7; int totalcnt;
 
 
int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
 
void coutrow(int num, int coef){ // obtain num * coef
    int temp = 1; int mxpw = 0;
    while(temp <= coef){
        temp*=2; mxpw++;
    }
    mxpw--;
    int tempnum = coef;
    temp /= 2;
    
    int pwline[100]; pwline[0] = num;
    bool bts[100];
    for(int i = 1; i <= mxpw; i++){
        pwline[i] = pwline[i - 1] * 2;
    }
    for(int i = 0; i < mxpw; i++){
        cout << pwline[i] << " + " << pwline[i] << endl; totalcnt--;
    }
    for(int i = 0; i <= mxpw; i++){
        if(tempnum%2==1){
            bts[i] = 1;
        }
        else{
            bts[i] = 0;
        }
        tempnum /= 2;
    }
    if(tempnum) cout << "BUG";
    int sum = 0;
    for(int i = 0; i <= mxpw; i++){
        if(bts[i]){
            cout << sum << " + " << pwline[i] << endl; totalcnt--;
            sum = sum + pwline[i];
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    
    int n; cin >> n; cout << "1000\n"; totalcnt = 1000;
    cout << n << " ^ " << n << "\n"; totalcnt--;
    int temp = 1;
    while(temp <= n){
        temp *= 2;
    }
    temp /= 2; int h = n * temp;
    coutrow(n, temp);
    cout << n << " ^ " << h << "\n"; h = (n xor h); totalcnt--;
    int newmod = modInverse(n, h); // newmod even is the main problem
    if(newmod % 2 == 1){
        coutrow(n, newmod);
        int d = n * newmod - 1; d = d / h;
        coutrow(h, d);
        d = d * h; cout << n * newmod << " ^ " << d; totalcnt--;
    }
    else{ // 3 * 2 = 6; 5;
        if((n + h) % 2) cout << "BUG";
        cout << n << " + " << h << "\n"; totalcnt--;
        h = n + h;
        int newmod = modInverse(n, h);
        coutrow(n, newmod);
        int d = n * newmod - 1; d = d / h;
        coutrow(h, d);
        d = d * h; cout << n * newmod << " ^ " << d; totalcnt--;
        
    }
    cout << "\n";
    for(int i = 1; i <= totalcnt; i++){
        cout << "1 + 1\n";
    }
}