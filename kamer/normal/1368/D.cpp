#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;
const int NUM = 20;
typedef long long ll;

int main(void) {
    vector<ll> counts(NUM, 0);
    vector<ll> powers(NUM, 1);
    for (int i = 1; i < NUM; i++) {
        powers[i] = powers[i - 1] * 2;
    }
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < NUM; j++) {
            if (a[i] % 2 == 1) counts[j]++;
            a[i] /= 2;
        }
    }
    ll maxSum = 0;
    for (int i = 0; i < n; i++) {
        ll currEl = 0;
        for (int j = 0; j < NUM; j++) {
            if (counts[j] > 0) {
                currEl += powers[j];
                counts[j]--;
            }
        }
        maxSum = maxSum + currEl * currEl;
    }
    cout << maxSum << "\n";
}