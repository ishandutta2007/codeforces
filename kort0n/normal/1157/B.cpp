#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
string S;
map<char, char> f;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> S;
    for(char i = '1'; i <= '9'; i++) cin >> f[i];
    int l = 0;
    while(S[l] >= f[S[l]]) {
        l++;
        if(l >= S.size()) break;
    }
    cerr << l << endl;
    if(l == S.size()) {
        cout << S << endl;
        return 0;
    }
    int r = l + 1;
    while(S[r] <= f[S[r]]) {
        r++;
        if(r >= S.size()) break;
    }
    cerr << r << endl;
    for(int i = 0; i < S.size(); i++) {
        if(l <= i && i < r) cout << f[S[i]];
        else cout << S[i];
    }
    cout << endl;
    return 0;
}