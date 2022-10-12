///////////////////////////
//   Just code it.
//   Today is 08/03/2018
//   
//..........................
//..........................
//..........................
//|*..|*..|*..|*..|*..|*..|*
//..|*..|*..|*..|*..|*..|*..
//..........................
//..........................
//..........................
////////////////////////////

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;
typedef vector<ll> vi;
typedef unsigned long long nat;
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ffi for(int i = 0; i < n; i++)
#define ffj for(int j = 0; j < m; j++)
#define all(any_vector) any_vector.begin(), any_vector.end()
#define re return
#define W(anything) cout << (anything) << endl;
#define R(something) cin >> (something);

//Code starts here

ll n, m, k, x, y;
map<long long, int> mm;
string s1, s2;

int main()
{
    R(n)
    R(m)
    if (m > 9 * n)
    {
        cout << "-1 -1";
        return 0;
    }
    if (n == 1 && m == 0)
    {
        cout << "0 0";
        re 0;
    }
    if (m == 0)
    {
        cout << "-1 -1";
        return 0;
    }
    k = m;
    for (int i = 0; i < n; i++)
    {
        s2 = s2 + (char)(min(9LL, k) + '0');
        k -= min(9LL, k);
    }
    for (int i = 0; i < n; i++)
    {
        if (m > 9) {
            s1 = s1 + "9";
            m-= 9;
        }
        else
        {
            s1 = s1 + char(m - 1 + '0');
            m = 1;
        }
        if (i == n - 1)
        {
            s1[i]++;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << s1[i];
    }
    cout << " " << s2;
}