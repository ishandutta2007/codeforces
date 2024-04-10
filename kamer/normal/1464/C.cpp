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
    ll n, T;
    cin >> n >> T;
    string S;
    cin >> S;
    vector<ll> powers(26, 1);
    for (int i = 1; i < 26; i++) powers[i] = powers[i - 1] * ((ll)2);
    vector<int> counts(26, 0);
    T = T - powers[S[n - 1] - 'a'];
    T = T + powers[S[n - 2] - 'a'];
    for (int i = 0; i < n - 2; i++) counts[S[i] - 'a']++;
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < counts[i]; j++) {
            if (T < ((ll)0)) T += powers[i];
            else T -= powers[i];
        }
    }

    if (T == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}