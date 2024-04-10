#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

int pw(int a, int b){
    if(b == 0) return 1;
    ll res = pw(a, b/2);
    res = (res*res)%MOD;
    if(b%2) res = (res*a)%MOD;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
	cout.precision(10);
	cout << fixed;

    int w, h;
    cin >> w >> h;
    cout << pw(2, w+h);
    return 0;
}