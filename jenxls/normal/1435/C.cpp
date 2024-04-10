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

const int N = 1e5 + 20;

int a[6];
int n, b[N];


int ptr[N];
set <pii> st;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    for (int i = 0; i < 6; i++) cin >> a[i];

    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + 6);
    sort(b, b + n);

    for (int i = 0; i < n; i++) {
        ptr[i] = 5;
        st.insert({b[i] - a[ptr[i]], i});
    }

    int ans = (*st.rbegin()).F - (st.begin() -> F);

    while (_sz(st)) {
        pii p = *st.begin();
        st.erase(p);

        int i = p.S;

        if (ptr[i] == 0) break;

        ptr[i]--;

        st.insert({b[i] - a[ptr[i]], i});

        ans = min(ans, (*st.rbegin()).F - (st.begin() -> F));
    }

    cout << ans << '\n';
}