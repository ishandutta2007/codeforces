#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int mul(int a, int b){
    return (1LL*a*b)%n;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int x){
    return pw(x, n-2);
}

int resi(int x){
    int x1 = inv((x-1));
    return mul(x1, x);
}

bool prime(int n){
    if(n < 2) return 0;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    if(n == 1){
        cout << "YES\n";
        cout << "1\n";
        return 0;
    }
    if(n == 4){
        cout << "YES\n";
        cout << "1\n3\n2\n4\n";
        return 0;
    }
    if(!prime(n)){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << "1\n";
    for(int i=2; i<n; i++){
        cout << resi(i) << "\n";
    }
    cout << n << "\n";
    return 0;
}