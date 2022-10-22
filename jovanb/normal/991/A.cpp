#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if(n == 0){cout << -1; return 0;}
    if(a >= n || b >= n){cout << -1; return 0;}
    int pas = a+b-c;
    if(a < c || b < c){cout << -1; return 0;}
    int fejl = n-pas;
    if(pas < 0 || fejl <= 0){cout << -1; return 0;}
    cout << fejl;
    return 0;
}