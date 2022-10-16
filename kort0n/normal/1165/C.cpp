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
    int n;
    string S;
    cin >> n >> S;
    string ans;
    char now = '!';
    for(int i = 0; i < S.size(); i++) {
        if(now == '!') {
            now = S[i];
            continue;
        }
        if(S[i] == now) continue;
        ans.push_back(now);
        ans.push_back(S[i]);
        now = '!';
    }
    cout << S.size() - ans.size() << endl;
    cout << ans << endl;
    return 0;
}