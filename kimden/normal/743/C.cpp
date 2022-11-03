#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    if(n == 1){
        cout << "-1" << endl;
    }else{
        cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
    }
    return 0;
}