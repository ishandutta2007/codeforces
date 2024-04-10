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
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> b(n, 0), ac(n, 0);
        bool ok = true;
        int j = 0, k = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == 'a') {
                ac[j]++;
                j++;
            }
            if(s1[i] == 'c') {
                ac[j] += 3;
                j++;
            }
            if(s2[i] == 'a') {
                ac[k]++;
                k++;
            }
            if(s2[i] == 'c') {
                ac[k] += 3;
                k++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(ac[i] != 2 && ac[i] != 6 && ac[i] != 0) {
                ok = false;
            }
        }
        ok &= (j == k);
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        vector<int> a1(n, 0), a2(n, 0), c1(n, 0), c2(n, 0);
        vector<pair<int, int>> b1, b2;
        for(int i = 0; i < n; i++) {
            if(i) {
                a1[i] += a1[i-1];
                a2[i] += a2[i-1];
                c1[i] += c1[i-1];
                c2[i] += c2[i-1];
            }
            if(s1[i] == 'a') {
                a1[i]++;
            }
            if(s1[i] == 'c') {
                c1[i]++;
            }
            if(s2[i] == 'a') {
                a2[i]++;
            }
            if(s2[i] == 'c') {
                c2[i]++;
            }
            if(s1[i] == 'b') {
                b1.push_back({a1[i], c1[i]});
            }
            if(s2[i] == 'b') {
                b2.push_back({a2[i], c2[i]});
            }
        }
        if(b1.size() != b2.size()) {
            cout << "NO\n";
            continue;
        }
        if(b2.size() == 0) ok = true;
        for(int i = 0; i < b2.size(); i++) {
            bool ok2 = false;
            ok2 |= (b1[i] == b2[i]);
            ok2 |= ((b1[i].first == b2[i].first) && (b1[i].second < b2[i].second));
            ok2 |= ((b1[i].first > b2[i].first) && (b1[i].second == b2[i].second));
            ok &= ok2;
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}