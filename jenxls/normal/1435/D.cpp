#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

const int N = 2e5 + 20;
int n, a[N];
char c[N];
stack <int> st;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> c[i];
        if (c[i] == '-') cin >> a[i];
    }

    for (int i = 0; i < 2 * n; i++) {
        if (c[i] == '+') st.push(i);
        else {
            if (st.empty()) return cout << "NO\n", 0;
            
            a[st.top()] = a[i];
            st.pop();
        }
    }

    if (!st.empty()) return cout << "NO\n", 0;

    set <int> S;

    for (int i = 0; i < 2 * n; i++) {
        if (c[i] == '+') S.insert(a[i]);
        else {
            if (S.empty() || *S.begin() != a[i]) return cout << "NO\n", 0;
            S.erase(S.begin());
        }
    }

    cout << "YES\n";
    for (int i = 0; i < 2 * n; i++)
        if (c[i] == '+') cout << a[i] << ' ';

    cout << '\n';
}