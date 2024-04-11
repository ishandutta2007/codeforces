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
    int now = 0;
    string ans;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '(') {
            if(now % 2 == 0) ans.push_back('0');
            else ans.push_back('1');
            now++;
            continue;
        } 
        if(now % 2 == 1) ans.push_back('0');
        else ans.push_back('1');
        now--;
    }
    cout << ans << endl;
    return 0;
}