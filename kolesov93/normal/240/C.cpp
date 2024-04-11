#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

vector<vector<int > > a;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        cout << "1 1 " << endl;
        return 0;
    }

    int ans = 0;
    int pw = 1;
    while (pw < n) {
        vector<int> c;
        for (int i = 0; i < n; ++i)
            if (i & pw) c.push_back(i + 1);
        a.push_back(c);
        pw += pw;
    }

    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i].size() << " ";
        for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << " ";
        cout << endl;
    }

    return 0;
}