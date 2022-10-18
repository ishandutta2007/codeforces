#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int c = 0;
    for (auto& x : a) {
        cin >> x;
    }
    
    int best1 = 0;
    int best2 = 1;
    long long best = std::numeric_limits<long long>::max();
    vector<int> index(10'000'001, -1);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (index[x] >= 0) {
            if (x < best) {
                best1 = index[x];
                best2 = i;
                best = x;
            }
        } else {
            index[x] = i;
        }
    }

    for (int g = 1; g <= 10'000'000; g++) {
        int idx = -1;
        for (int h = g; h <= 10'000'000; h+=g) {
            if (index[h] > -1) {
                if (idx == -1) 
                    idx = index[h];
                else {
                    long long l = (a[idx] / g * (long long)h);
                    if (l < best) {
                        best = l;
                        best1 = idx;
                        best2 = index[h];
                    }
                    break;
                }
            }
        }
    }

    if (best1 > best2)
        swap(best1, best2);
    cout << best1 + 1 << " " << best2 + 1 << '\n';
}