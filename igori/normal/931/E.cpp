///////////////////////////
//   Just code it.
//   Today is 10/03/2018
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
#define ffj for(int j = 0; j < n; j++)
#define ffk for(int k = 0; k < n; k++)
#define all(any_vector) any_vector.begin(), any_vector.end()
#define re return
#define W(anything) cout << (anything) << endl;
#define R(something) cin >> (something);

//Code starts here

ll n, m, x, y;
int mm[100][5200][100];
////////letter, dist, letter_on_dist, count;
string s;


int main()
{
    R(s);
    n = s.sz;
    s = s + s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mm[s[i] - 'a'][j][s[i + j] - 'a']++;
        }
    }
    double ans = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        double vari = 0;
        for (int j = 0; j < n; j++)
        {
            int countly = 0;
            for (char k = 'a'; k <= 'z'; k++)
            {
                if (mm[i - 'a'][j][k - 'a'] == 1)
                {
                    countly++;
                }
            }
            //cout << i << " " << j << " " << countly << endl;
            vari = max(vari, countly / (double)n);
        }
        ans += vari;
    }
    printf("%.9f", ans);
}