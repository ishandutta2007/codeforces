#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3;
int arr[maxn];

main() {
    string s;
    cin >> s;
    int n = s.size() + 1;
    s = s + "b";
    vector<pair<int, int>> sega;
    pair<int, int> p = {-1, -1};
    char l = 'z';
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' && l != 'a') {
            p.first = i;
        }
        if (s[i] != 'a' && i != 0 && s[i - 1] == 'a') {
            p.second = i - 1;
            sega.push_back(p);
        }
        l = s[i];
    }
    for (auto elem : sega) {
        if (elem.first != 0) {
            arr[elem.first - 1] = 1;
        }
        arr[elem.second] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}