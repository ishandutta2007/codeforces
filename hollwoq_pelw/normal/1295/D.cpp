#include <bits/stdc++.h>
using namespace std;

void phi(long long n){
    long long res = n;
    for (int i = 2; i <= floor(sqrt(n)); i++){
        if (n%i==0){
            res = res*(i-1)/i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if (n > 1){
        res = res/n*(n-1);
    }
    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        long long a,m;
        cin >> a >> m;
        phi(m/__gcd(a,m));
    }
}