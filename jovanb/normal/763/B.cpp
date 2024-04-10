#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    cout << "YES\n";
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += 1000000000;
        b += 1000000000;
        cout << (2*(a%2)+(b%2))%4 + 1 << "\n";
    }
    return 0;
}