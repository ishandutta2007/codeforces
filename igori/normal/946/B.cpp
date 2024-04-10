///////////////////////////
//   Just code it.
//   Today is 07/03/2018
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
#define ww(anything) cout << (anything) << endl;
#define rr(something) cin >> (something);

//Code starts here

ll n, m, k;

int main()
{
    rr(n); rr(m);
    while (n > 0 && m > 0)
    {
        if (n >= 2 * m)
        {
            n = n % (2 * m);
        }
        else
        {
            if (m >= 2 * n)
            {
                m = m % (2 * n);
            }
            else
            {
                break;
            }
        }
    }
    cout << n << " " << m;
}