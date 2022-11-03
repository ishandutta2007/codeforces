#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int gcd(int a, int b){
    return (b ? gcd(b, a%b) : a);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int a,b,n;
    cin >> a >> b >> n;
    while(1){
        n -= gcd(a,n);
        if(!n){
            cout << "0";
            return 0;
        }
        n -= gcd(b,n);
        if(!n){
            cout << "1";
            return 0;
        }
    }
    return 0;
}