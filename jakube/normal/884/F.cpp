#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> cnt(26, 0);
    vector<int> pairs;
    for (int i = 0; i < n/2; i++) {
        if (s[i] == s[n-i-1]) {
            pairs.push_back(i);
            if (v[i] < v[n-1-i]) {
                cnt[s[i] - 'a']++;
            } else {
                cnt[s[n-1-i] - 'a']++;
            }
        }
    }
    
    int m = pairs.size();
    if (*max_element(cnt.begin(), cnt.end()) * 2 <= m) {
        int sum = 0;
        for (int i = 0; i < n/2; i++) {
            if (s[i] == s[n-i-1]) {
                sum += max(v[i], v[n-i-1]);
            } else {
                sum += v[i] + v[n-i-1];
            }
        }
        cout << sum << endl;
    } else {
        char c = 'a' + (max_element(cnt.begin(), cnt.end()) - cnt.begin());
        vector<int> x;
        int sum = 0;
        for (int i = 0; i < n/2; i++) {
            if (s[i] == s[n-i-1]) {
                sum += max(v[i], v[n-i-1]);
            } else {
                sum += v[i] + v[n-i-1];
                if (s[i] != c && s[n-1-i] != c) {
                    x.push_back(min(v[i], v[n-1-i]));
                }
            }
        }
        sort(x.begin(), x.end());
        for (int i = 0; i < 2*cnt[c-'a'] - m; i++) {
            sum -= x[i]; 
        }
        cout << sum << endl;
    }
}