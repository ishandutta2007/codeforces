#include<bits/stdc++.h>
#pragma GCC optimization("Ofast")
#pragma GCC target("avx2")
#pragma once
using namespace std;
typedef long long ll;
#define F first
#define S second
const ll mod=1e9+7;
int q, n, m, k, a[200001], c[20];
set<ll> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while(q--){
        cin >> n >> m;
//        n=q/10+3;
//        m=q%10+3;
//        cout << n << " " << m << "\n";
        s.clear();
        for(int i=0; i<=2; i++){
            c[0]=__gcd(n-i, m-2+i);
            c[2]=sqrt(c[0]);
            for(int t=1; t<=c[2]; t++){
                if(c[0]%t==0){
                    s.insert(t);
                    s.insert(c[0]/t);
                }
            }
        }
        if(n%2!=m%2)s.insert(2);
        cout << s.size() << " ";
        for(auto i : s)cout << i << " ";
        cout << "\n";
    }
    return 0;
}