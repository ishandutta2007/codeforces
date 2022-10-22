#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        auto rev = [&](string s) {
            string t = s;
            reverse(t.begin(), t.end());
            return t;
        };
        auto hash = [](string s) {
            int ans = 0;
            for(int i = 0; i < s.size(); i++) {
                ans *= 300;
                ans += s.at(i);
            }
            return ans;
        };
        for(int i = 0; i < n; i++) cin >> v[i];
        bool ok = false; 
        for(int i = 0; i < n; i++) {
            if(v[i] == rev(v[i])) ok = true;
        }
        set<int> s2, s3;
        for(int i = 0; i < n; i++) {
            if(v[i].size() == 2) {
                if(s2.count(hash(rev(v[i])))) ok = true;
                s2.insert(hash(v[i]));
                s3.insert(hash(v[i]));
            }
            if(v[i].size() == 3) {
                if(s3.count(hash(rev(v[i])))) ok = true;
                if(s3.count(hash(rev(v[i]).substr(0, 2)))) ok = true;
                s3.insert(hash(v[i]));
                s2.insert(hash(v[i].substr(0, 2)));
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}