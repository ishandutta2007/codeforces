#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 9;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    while (cin >> n) {
        vector<int> s(n);
        int s1 = 0, s2 = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            vector<int> a(s[i]);
            for (int j = 0; j < s[i]; j++) {
                cin >> a[j];
            }
            for (int j = 0; j < s[i] / 2; j++) s1 += a[j];
            for (int j = s[i] - 1; s[i] - j <= s[i] / 2; j--) s2 += a[j];
            if (s[i] % 2) v.push_back(a[s[i] / 2]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (i % 2 == 0) s1 += v[i];
            else s2 += v[i];
        }
        cout << s1 << " " << s2 << endl;
    }

	return 0;
}