#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
using namespace std;
set<ll> ans;

void doit(ll x, ll a, ll n, ll tours) {
    if (x <= 0) return;
    if (x >= 1e10) return;
    if (a < 0 && a != -1) return;

    if (x & 1)
    if ((x * x <= n || a == -1) && x * x + a * x == n) {
        ans.insert(x << tours);
    }
}

void check(ld res, ll a, ll n, ll tours) {
    ll c = res;
    for (ll diff = -100; diff <= 100; ++diff) {
        doit(c + diff, a, n, tours);
    }
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    ll n;
    cin >> n;
    n += n;

    ll a = -1;
    ll tours = 0;

    while ((1LL << (tours)) - 1 <= n && 1 + a <= n) {
        ld A = a; 

        ld D = A * A + ld(n) * 4;
        if (D >= 0) {
            ld sqd = sqrtl(D);
            if (sqd >= 0) {
                check((-A + sqd) / 2., a, n, tours); 
                check((-A - sqd) / 2., a, n, tours); 
            }
        }
        
        ++tours;
        a += (1LL << tours);
    }

    if (ans.size() == 0) {
        puts("-1");
    } else {
        for (set<ll>::iterator it = ans.begin(); it != ans.end(); ++it) {
            cout << *it << endl;
        }
    }

    return 0;
}