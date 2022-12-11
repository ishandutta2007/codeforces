#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <random>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmax = 1e7 + 100;

int mind[nmax];
vector<int> primes;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i = 2; i < nmax; ++i) {
        mind[i] = i;
    }
    for (int i = 2; i < nmax; ++i) {
        if (mind[i] == i) {
            primes.pb(i);
            for (int j = 2 * i; j < nmax; j += i) {
                if (mind[j] > i) {
                    mind[j] = i;
                }
            }
        }
    }

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> setik;
    int lst;
    for (int i = 0; i < n; ++i) {
        int val = a[i];
        bool valid = true;
        while (val > 1) {
            int p = mind[val];
            if (setik.count(p)) {
                valid = false;
                break;
            }
            val /= p;
        }
        if (!valid) {
            break;
        } else {
            val = a[i];
            while (val > 1) {
                int p = mind[val];
                setik.insert(p);
                val /= p;
            }
            lst = i;
        }
    }

    setik.clear();
    for (int i = 0; i <= lst; ++i) {
        int val = a[i];
        cout << val << " ";
        while (val > 1) {
            int p = mind[val];
            setik.insert(p);
            val /= p;
        }
    }

    int ptr = 0;

    for (int i = lst + 1; i < n; ++i) {
        if (i == lst + 1) {
            for (int j = a[i] + 1; ; ++j) {
                int val = j;
                bool ok = true;
                while (val > 1) {
                    int p = mind[val];
                    if (setik.count(p)) {
                        ok = false;
                        break;
                    }
                    val /= p;
                }
                if (ok) {
                    cout << j << " ";
                    while (j > 1) {
                        int p = mind[j];
                        setik.insert(p);
                        j /= p;
                    }
                    break;
                }
            }
            continue;
        }
        while (setik.count(primes[ptr])) {
            ++ptr;
        }
        cout << primes[ptr] << " ";
        if (i == lst + 1) {
            setik.insert(primes[ptr]);
            ptr = 0;
        } else {
            ++ptr;
        }
    }

    cout << "\n";

}