#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
bool f(int n)
{
   if(n==0) return false;
   return (ceil(log2(n)) == floor(log2(n)));
}
void solve(){
    int n;
    cin >> n;
    if(isPrime(n)) cout<<"Bob"<<endl;
    else{
        if(n % 2 == 0){
            if(f(n)){
                if((int)floor(log2(n)) % 2 == 0) cout<<"Alice"<<endl;
                else cout<<"Bob"<<endl;
            }
            else cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}