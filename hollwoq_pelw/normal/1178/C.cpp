#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

long long p(int n){
    if (n == 0) return 1;
    if (n == 1) return 2;
    long long x = p(n/2);
    return ((x*x)%mod*p(n%2))%mod;
}
int main(){
    int w,h;
    cin >> w >> h;
    cout << p(w+h);//2^(w+h)
}