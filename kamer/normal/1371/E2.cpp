#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int lower_bound = a[n - 1] - n + 1;
    vector<int> count(n, 0);
    int currIndex = 0;
    for (; currIndex < n; currIndex++) {
        if (a[currIndex] <= lower_bound) count[0]++;
        else break;
    }
    for (int i = 1; i < n; i++) {
        count[i] = count[i - 1];
        while (a[currIndex] == lower_bound + i) {
            count[i]++;
            currIndex++;
        }
    }
    int countIndex = 0;
    while (count[countIndex] < p) countIndex++;
    int limSup = countIndex;

    for (int i = 1; i < n; i++) {
        if (p + i - count[i] <= i) {
            limSup = min(limSup, p + i - count[i]);
        }
    }

    int limInf = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] - i <= 0) limInf = max(limInf, i - count[i] + 1);
    }

    limSup = max(0, limSup);
    cout << max(limSup - limInf, 0) << "\n";
    for (int num = lower_bound + limInf; num < lower_bound + limSup; num++) {
        cout << num << " ";
    }
}