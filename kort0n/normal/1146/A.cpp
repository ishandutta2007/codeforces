#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int a = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') a++;
    }
    cout << min((int)s.size(), a * 2 - 1) << endl;
    return 0;
}