#include <bits/stdc++.h>
using namespace std;

long long get(long long n, long long p, long long k){
    long long ans = 0;
    
    while(n) ans += (n/=p);
    
    return ans/k;
}

int main(){
    long long n,b;
    long long ans = LLONG_MAX;
    cin >> n >> b;
    for (long long p = 2; p <= b; p++){
        if (p*p > b) p = b;
        int v = 0;
        while(b%p==0) {b/=p;v++;} 
        //cout << v << endl;
        if (v) ans = min(ans, get(n,p,v));
    }
    cout << ans;
    return 0;
}