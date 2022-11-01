#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 1e5 + 5;
const int inf = 1e8;
const double eps = 1e-8;
const int base = 1073676287;

void read(int& x) {
    scanf("%d", &x);
}
 
void read(int& x, int& y) {
    scanf("%d %d", &x, &y);
}

string s[maxn];

int fd(string& t) {
    int ans = inf;
    for (int i = 0; i < t.size(); i++)
        if (t[i] >= '0' && t[i] <= '9')
            ans = min(ans, min(i, (int)t.size() - i));
    return ans;
}

int fl(string& t) {
    int ans = inf;
    for (int i = 0; i < t.size(); i++)
        if (t[i] >= 'a' && t[i] <= 'z')
            ans = min(ans, min(i, (int)t.size() - i));
    return ans;
}

int fs(string& t) {
    int ans = inf;
    for (int i = 0; i < t.size(); i++)
        if (t[i] == '#' || t[i] == '*' || t[i] == '&')
            ans = min(ans, min(i, (int)t.size() - i));
    return ans;
}
int main() {
    int n, m;
    read(n, m);

    for (int i = 0; i < n; i++)
        cin >> s[i];

    int ans = inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                if (i == j || j == k || i == k) continue;
                ans = min(ans, fd(s[i]) + fl(s[j]) + fs(s[k]));
            }
    cout << ans;
    return 0;
}