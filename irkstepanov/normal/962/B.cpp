#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int a, b;

void solve(int x) {
    //cout << x << endl;
    if (a >= b) {
        a = max(0, a - (x + 1) / 2);
        b = max(0, b - x / 2);
    } else {
        a = max(0, a - x / 2);
        b = max(0, b - (x + 1) / 2);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n >> a >> b;

    int sum = a + b;

    string s;
    cin >> s;
    s += "*";
    int prev = -1;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '*' && prev != -1) {
            solve(i - prev);
            prev = -1;
            continue;
        } else if (s[i] == '.' && prev == -1) {
            prev = i;
        }
    }

    cout << sum - (a + b) << endl;

}