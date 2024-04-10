#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define data NE_data
#define rank NE_rank
#define time NE_time
#define endl '\n'

int arr1[1000000];
int arr2[1000000];

bool cmp1(int i, int j) {
    return arr1[i] < arr1[j];
}

bool cmp2(int i, int j) {
    return arr2[i] < arr2[j];
}
void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    vector<int> inds1(n), inds2(n);
    for (int i = 0; i < n; i++) {
        inds1[i] = i;
        inds2[i] = i;
    }

    sort(inds1.begin(), inds1.end(), cmp1);
    sort(inds2.begin(), inds2.end(), cmp2);

    vector<int> pos1(n), pos2(n);
    for (int i = 0; i < n; i++) {
        pos1[inds1[i]] = i;
        pos2[inds2[i]] = i;
    }

    vector<int> suf1(n), suf2(n);

    for (int i = n - 1; i >= 0; i--) {
        suf1[i] = pos2[inds1[i]];
        if (i != n - 1) {
            suf1[i] = min(suf1[i], suf1[i + 1]);
        }

        suf2[i] = pos1[inds2[i]];
        if (i != n - 1) {
            suf2[i] = min(suf2[i], suf2[i + 1]);
        }
    }


    int ind1 = n - 1;
    int ind2 = n - 1;

    while (true) {
        bool was = false;
        if (suf1[ind1] < ind2) {
            was = true;
            ind2 = suf1[ind1];
        }

        if (suf2[ind2] < ind1) {
            was = true;
            ind1 = suf1[ind2];
        }

        if (!was) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (pos1[i] >= ind1 || pos2[i] >= ind2);
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}