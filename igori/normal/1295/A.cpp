#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll n, x;
string s;

void solve()
{
    cin >> n;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2) cout << 1;
    }
    else
    {
        cout << 7;
        n -= 3;
        for (int i = 0; i < n; i += 2) cout << 1;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}