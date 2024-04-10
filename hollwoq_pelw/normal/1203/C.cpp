#include <bits/stdc++.h>
using namespace std;
void s(long long m){
    long long res = 1, i = 2;
    while(m > 1){
        if (i > sqrt(m)){
            i = m;
        }
        int s = 1;
        while (m%i==0){
            m/=i;
            s++;
        }
        res *= s;
        i++;
    }
    cout << res;
}
int main(){
    long long n,a,m;
    cin >> n;
    for (long long i =0; i < n; i++){
        cin >> a;
        if (i == 0) m = a;
        else m = __gcd(m,a);
    }
    s(m);
    return 0;
}