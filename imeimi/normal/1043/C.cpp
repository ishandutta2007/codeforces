#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

char in[1001];
char ot[1001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> in;
    int n = strlen(in);
    for (int i = 0; i < n; ++i) ot[i] = in[i];
    sort(ot, ot + n);
    vector<int> ans;
    for (int i = n; i--; ) {
        if (ot[i] != in[i]) {
            reverse(ot, ot + i);
            ans.push_back(1);
        }
        else ans.push_back(0);
    }
    for (int i = n; i--; ) printf("%d ", ans[i]);
    return 0;

}