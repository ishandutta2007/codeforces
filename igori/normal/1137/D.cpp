#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <time.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#define td typedef
td long long ll;

#define pb push_back
#define fi first
#define se second
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(x) x.begin(), x.end()

const long long INFLL = 4e18;
const long long INF = 1e9;

using namespace std;
const int MOD = 1e9 + 7;
ll n;

int read()
{
    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++) cin >> s;
    return t;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    while(1)
    {
        cout << "next 0" << endl;
        read();
        cout << "next 0 1" << endl;
        if (read() == 2)
            break;
    }
    while(1)
    {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        if (read() == 1)
        {
            cout << "done" << endl;
            return 0;
        }
    }
}