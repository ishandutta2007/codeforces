#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll p0[100005];
ll p1[100005];
ll s0[100005];
ll s1[100005];
ll pc[100005];
ll sc[100005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    ll x, y;
    cin >> x >> y;
    int n = s.size();
    if(x > y){
        swap(x, y);
        for(int i=0; i<n; i++){
            if(s[i] == '0') s[i] = '1';
            else if(s[i] == '1') s[i] = '0';
        }
    }
    for(int i=1; i<=n; i++){
        p0[i] = p0[i-1];
        p1[i] = p1[i-1];
        pc[i] = pc[i-1];
        if(s[i-1] != '1'){
            pc[i] += y*p1[i-1];
            p0[i]++;
        }
        else{
            pc[i] += x*p0[i];
            p1[i]++;
        }
    }
    for(int i=n; i>=1; i--){
        s0[i] = s0[i+1];
        s1[i] = s1[i+1];
        sc[i] = sc[i+1];
        if(s[i-1] != '0'){
            sc[i] += y*s0[i+1];
            s1[i]++;
        }
        else{
            sc[i] += x*s1[i+1];
            s0[i]++;
        }
    }
    ll res = 1000000000000000000LL;
    for(int i=1; i<=n+1; i++){
        res = min(res, pc[i-1] + sc[i] + x*p0[i-1]*s1[i] + y*p1[i-1]*s0[i]);
    }
    cout << res;
    return 0;
}