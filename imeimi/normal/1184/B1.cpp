#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int s, b;
int A[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> b;
    for (int i = 1; i <= s; ++i) cin >> A[i];
    vector<pii> v;
    v.emplace_back(0, 0);
    for (int i = 0; i < b; ++i) {
        int d, g;
        cin >> d >> g;
        v.emplace_back(d, g);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        v[i].second += v[i - 1].second;
    }
    for (int i = 1; i <= s; ++i) {
        printf("%d ", prev(lower_bound(v.begin(), v.end(), pii(A[i], 2e9)))->second);
    }
    return 0;
}