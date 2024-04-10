#include "bits/stdc++.h"
using namespace std;

using lol = long long;
using ii = pair<int, int>;
using ll = pair<lol, lol>;

const int inf = INT_MAX / 2;

void solve(){
    int n; char c;
    cin >> n >> c;

    string s;
    cin >> s;

    if(c == 'g'){
        cout << "0\n";
        return;
    }

    vector<int> pos[26];

    for(int i = 0; i < n; ++i){
        pos[s[i] - 'a'].push_back(i);
    }

    sort(pos['r' - 'a'].begin(), pos['r' - 'a'].end());
    sort(pos['g' - 'a'].begin(), pos['g' - 'a'].end());
    sort(pos['y' - 'a'].begin(), pos['y' - 'a'].end());

    int ans = 0;

    for(int i = 0; i < n; ++i) if(s[i] == c){
        int j = upper_bound(pos['g' - 'a'].begin(), pos['g' - 'a'].end(), i) - pos['g' - 'a'].begin();
        int k = pos['g' - 'a'][0];
        j = (j != pos['g' - 'a'].size() ? pos['g' - 'a'][j] : inf);

        ans = max(ans, min(k + 1 + n - i - 1, j - i));
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}