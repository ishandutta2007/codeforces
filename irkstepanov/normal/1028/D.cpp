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
#include <cstring>
#include <cmath>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    set<pii> global;
    //set<int> lf, rg;

    int q;
    cin >> q;

    int ans = 1;

    while (q--) {
        string s;
        cin >> s;
        int val;
        cin >> val;
        if (s == "ADD") {
            set<pii>::iterator nx = global.lower_bound({val, 0});
            int z = 0;
            if (!global.empty()) {
                if (nx != global.begin()) {
                    set<pii>::iterator it = nx;
                    --it;
                    if (it->second == 2) {
                        z = 2;
                    }
                }
                if (nx != global.end()) {
                    if (nx->second == 1) {
                        z = 1;
                    }
                }
            }
            global.insert({val, z});
        } else {
            set<pii>::iterator it = global.lower_bound({val, 0});
            bool dosth = true;
            if (it->second == 0) {
                add(ans, ans);
            } else {
                if (it->second == 2 && it != global.begin()) {
                    set<pii>::iterator pr = it;
                    --pr;
                    if (pr->second == 2) {
                        cout << "0\n";
                        return 0;
                    }
                }
                if (it->second == 1 && it != --global.end()) {
                    set<pii>::iterator nx = it;
                    ++nx;
                    if (nx->second == 1) {
                        cout << "0\n";
                        return 0;
                    }
                }
                //dosth = false;
            }

            if (dosth) {
                set<pii>::iterator pr = it;
                if (pr != global.begin()) {
                    --pr;
                    while (true) {
                        if (pr->second == 0) {
                            if (pr == global.begin()) {
                                pii p = {pr->first, 1};
                                global.erase(pr);
                                global.insert(p);
                                break;
                            } else {
                                set<pii>::iterator z = pr;
                                --z;
                                pii p = {pr->first, 1};
                                global.erase(pr);
                                global.insert(p);
                                pr = z;
                            }
                        } else if (pr->second == 2) {
                            ans = 0;
                            break;
                        } else {
                            break;
                        }
                    }
                }


                set<pii>::iterator nx = it;
                ++nx;
                while (nx != global.end()) {
                    if (nx->second == 0) {
                        set<pii>::iterator z = nx;
                        ++z;
                        pii p = {nx->first, 2};
                        global.erase(nx);
                        global.insert(p);
                        nx = z;
                    } else if (nx->second == 1) {
                        ans = 0;
                        break;
                    } else {
                        break;
                    }
                }
            }


            if (ans == 0) {
                cout << "0\n";
                return 0;
            }

            global.erase(it);
        }
    }

    int cnt = 0;

    for (auto it : global) {
        if (it.second == 0) {
            ++cnt;
        }
    }
    mul(ans, cnt + 1);
    cout << ans << "\n";

}