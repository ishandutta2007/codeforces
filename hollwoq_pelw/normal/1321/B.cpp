#include <bits/stdc++.h>
using namespace std;

long long n,b;
map<long long, long long> bt;

int main(){
    cin >> n;
    // cout << n*(n+1)/2;
    for (long long i = 0; i < n; i++){
        cin >> b;
        bt[b-i]+=b;
    }
    long long mx = -1;
    for (auto p:bt){
        mx = max(mx, p.second);
    }
    cout << mx;
    return 0;
}