#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    string s;
    cin >> s;
    int n = s.length();
    ll x, y;
    cin >> x >> y;
    bool flip = false;
    if (x < y) {
        flip = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') s[i] = '1';
            else if (s[i] == '1') s[i] = '0';
        }
        ll temp = x;
        x = y;
        y = temp;
    }

    vector<int> poss;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') poss.push_back(i);
    }
    int k = poss.size();

    vector<ll> zero_pref(n, 0);
    vector<ll> one_pref(n, 0);
    vector<ll> zero_suf(n, 0);
    vector<ll> one_suf(n, 0);

    for (int i = 0; i < n - 1; i++) {
        zero_pref[i + 1] = zero_pref[i];
        one_pref[i + 1] = one_pref[i];
        if (s[i] == '0') zero_pref[i + 1]++;
        else if (s[i] == '1') one_pref[i + 1]++;
    }

    for (int i = n - 2; i >= 0; i--) {
        zero_suf[i] = zero_suf[i + 1];
        one_suf[i] = one_suf[i + 1];
        if (s[i + 1] == '0') zero_suf[i]++;
        else if (s[i + 1] == '1') one_suf[i]++;
    }

    ll current_result = 0;
    ll seen_ques = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') current_result += (y * (seen_ques + one_pref[i]));
        else current_result += (x * zero_pref[i]);
        if (s[i] == '?') seen_ques++;
    }

    ll final_result = current_result;
    for (ll i = k - 1; i >= 0; i--) {
        ll pos = poss[i];
        current_result -= (x * zero_pref[pos]);
        current_result -= (y * (zero_suf[pos] + k - 1 - i));
        current_result += (y * (one_pref[pos] + i));
        current_result += (x * one_suf[pos]);
        final_result = min(final_result, current_result);
    }

    cout << final_result << "\n";
}