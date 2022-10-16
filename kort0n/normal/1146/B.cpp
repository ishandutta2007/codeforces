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
    string t;
    cin >> t;
    int index = 0;
    int sum = 0;
    while(true) {
        if(index == t.size()) {
            cout << ":(" << endl;
            return 0;
        }
        if(t[index] != 'a') sum++;
        if(t.size() == index + sum + 1) break;
        index++;
    }
    //cout << index << endl;
    string ans = t.substr(0, index + 1);
    string NEW = ans;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] != 'a') NEW.push_back(ans[i]);
    }
    if(NEW == t) cout << ans << endl;
    else cout << ":(" << endl;
    return 0;
}