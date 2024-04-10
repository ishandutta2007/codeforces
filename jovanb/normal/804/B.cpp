#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int pw(int a, int b){
    if(b == 0){
        return 1;
    }
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    int res = 0;
    int cnt = 0;
    for(auto c : s){
        if(c == 'a') cnt++;
        else res = add(res, pw(2, cnt)-1);
    }
    cout << res;
    return 0;
}