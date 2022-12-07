#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
using namespace std;

const int N = 1111;
char w[N], s[N];
int n;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    gets(w);
    n = strlen(w);
    int k;
    cin >> k;

    vector< pair<int, char> > a;
    for (char c = 'a'; c <= 'z'; ++c) {
        int cnt = count(w, w + n, c);
        if (cnt > 0) {
            a.push_back(make_pair(cnt, c)); 
        }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    if (a.size() > k) {
        puts("-1");
        return 0;
    }
    
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;

        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) {
            cnt += (a[i].first + mid - 1) / mid;
        }
        if (cnt > k) l = mid + 1;
        else r = mid;
    }

    cout << l << endl;
    for (int i = 0; i < a.size(); ++i) {
        int cnt = (a[i].first + l - 1) / l;
        for (int j = 0; j < cnt; ++j) putchar(a[i].second);
        k -= cnt;
    }
    while (k--) putchar('a');
    puts("");

    return 0;
}