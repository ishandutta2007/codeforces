#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll cnt = 1;
    while(k % 2 == 0){
        k /= 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}