#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5, MAXLN = 100;
int arr[MAXN];
vector<int> al[MAXLN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        int x = arr[i];
        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            cnt++;
        }
        al[cnt].push_back(arr[i]);
    }
    int maxi = 0;
    for (int i = 0; i < MAXLN; ++i) {
        if (al[i].size() > al[maxi].size()) {
            maxi = i;
        }
    }
    cout << n - al[maxi].size() << endl;
    for (int i = 0; i < MAXLN; ++i) {
        if (i == maxi) {
            continue;
        }
        for (auto elem : al[i]) {
            cout << elem << " ";
        }
    }
    return 0;
}