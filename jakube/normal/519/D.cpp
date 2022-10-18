#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> v(26);
    for (int idx = 0; idx < 26; idx++)
        cin >> v[idx];
    
    string s;
    cin >> s;
    
    set<long long> se;
    long long psum = 0;
    for (char c : s) {
        se.insert(psum);
        psum += v[c-'a'];
    }
    se.insert(psum);

    vector<long long> numbers(se.begin(), se.end());
    vector<vector<int>> cnts(26, vector<int>(numbers.size(), 0));

    psum = 0;
    for (char c : s) {
        int idx = lower_bound(numbers.begin(), numbers.end(), psum) - numbers.begin();
        cnts[c - 'a'][idx]++;
        psum += v[c - 'a'];
    }

    psum = 0;
    long long cnt = 0;
    for (char c : s) {
        int idx = lower_bound(numbers.begin(), numbers.end(), psum) - numbers.begin();
        cnts[c - 'a'][idx]--;

        psum += v[c - 'a'];

        idx = lower_bound(numbers.begin(), numbers.end(), psum) - numbers.begin();
        cnt += cnts[c - 'a'][idx];
    }

    cout << cnt << endl;

    return 0;
}