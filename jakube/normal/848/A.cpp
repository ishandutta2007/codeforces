#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    vector<char> v;

    for (char c = 'a'; c <= 'z'; c++) {
        int sum = 0;
        int cnt = 1;
        v.push_back(c);
        while (sum + cnt <= k) {
            sum += cnt;
            cnt++;
            v.push_back(c);
        }
        k -= sum;
    }
    cout << std::string(v.begin(), v.end()) << endl;
}