#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++) {
        cin >> v[idx];
        v[idx]--;
    }
    
    vector<int> sizes;
    vector<bool> cycle(n, false);
    vector<int> cnts(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (cycle[i]) continue;

        int c = 1;
        cycle[i] = true;
        int j = v[i];
        while (i != j) {
            cycle[j] = true;
            j = v[j];
            c++;
        }

        sizes.push_back(c);
        cnts[c]++;
    }

    vector<int> reduced;
    for (int i = 0; i < cnts.size(); i++) {
        if (cnts[i]) {
            int val = cnts[i];
            for (int j = 0; (1 << j) <= val; j++) {
                reduced.push_back(i << j);
                val -= 1 << j;
            }
            if (val)
                reduced.push_back(i * val);
        }
    }

    const int N = 1000001;
    bitset<N> bs;
    bs.set(0);
    for (int num : reduced) {
        bs |= bs << num;
    }

    cout << (bs.test(k) ? k : k + 1) << " ";

    int t = accumulate(sizes.begin(), sizes.end(), 0, [](int a, int b){ return a + b / 2; });
    if (k <= t) {
        cout << k * 2 << endl;
    } else {
        cout << min(n, k + t) << endl;
    }

    return 0;
}