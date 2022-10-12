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
#define ffj for(int j = 0; j < n; j++)
#define ffk for(int k = 0; k < n; k++)
#define all(any_vector) any_vector.begin(), any_vector.end()
#define re return
#define W(anything) cout << (anything) << endl;
#define R(something) cin >> (something);

//Code starts here

ll n, m, x, y;
map<int, int> mm;
string s1, s2;
ll a[454], b[454];

int main()
{
    R(n);
    R(s1);
    ffi mm[s1[i] - 'a']++;
    n = 26;
    ffi if (mm[i] == 0 && mm[i + 'A' - 'a'] == 0) {W("NO"); re 0;}
    W("YES");
}