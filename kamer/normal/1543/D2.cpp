#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

vector<int> convert(int n, int k) {
    vector<int> res;
    while (n != 0) {
        res.push_back(n % k);
        n /= k;
    }
    return res;
}

int revert(vector<int> a, int k) {
    int pow = 1;
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += (a[i] * pow);
        pow *= k;
    }
    return res;
}

vector<int> sum(vector<int> a, vector<int> b, int k) {
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        res.push_back((a[i] + b[i]) % k);
    }
    return res;
}

vector<int> diff(vector<int> a, vector<int> b, int k) {
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        res.push_back((a[i] - b[i] + k) % k);
    }
    return res;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int count = 0;
        for (int i = 0; i < n; i++) {
            auto count_v = convert(count, k);
            auto i_v = convert(i, k);
            int guess = -1;
            if (i % 2 == 0) guess = revert(sum(count_v, i_v, k), k);
            else guess = revert(diff(count_v, i_v, k), k);
            cout << guess << "\n";
            cout.flush();
            int res;
            cin >> res;
            if (res == 1) break;
            if (res == -1) {
                return -1;
            }
            count = revert(diff(convert(guess, k), count_v, k), k);
        }
    }
}