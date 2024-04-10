#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> psum(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        psum[i+1] = psum[i] + (s[i] == '1');
    }

    long long total = 0;
    for (int i = k; i <= s.size(); i++) {
        if (k) 
            total += (long long)(upper_bound(psum.begin(), psum.end(), i) - lower_bound(psum.begin(), psum.end(), i)) * (long long)(upper_bound(psum.begin(), psum.end(), i-k) - lower_bound(psum.begin(), psum.end(), i-k));
        else {
            long long n = (long long)(upper_bound(psum.begin(), psum.end(), i) - lower_bound(psum.begin(), psum.end(), i));
            if (n)
                total += (n-1)*n/2;
        }
    }
    cout << total << endl;

    return 0;
}