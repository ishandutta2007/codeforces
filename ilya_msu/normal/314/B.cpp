#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:128000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 1000 * 1000 * 1000 + 10;


int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int b, d;
    string a, c;
    cin >> b >> d >> a >> c;
    pii init(-1, -1);
    vector<pii> ac(a.size(), init);
    int ic = 0, ia = 0, ca = 0, cc = 0;
    while(true) {
        if ((cc == 0) && (ca > c.size() + 1)) {
            cout << 0 << endl;
            return 0;
        }
        if (a[ia] == c[ic]) {
            ++ic;
            ++ia;
            if (ic == c.size()) {
                ic = 0;
                ++cc;
                if (ac[ia - 1] == init) {
                    ac[ia - 1] = pii(ca, cc);
                }
                else {
                    break;
                }
            }
        }
        else {
            ++ia;
        }
        if (ia == a.size()) {
            ia = 0;
            ++ca;
        }
        if (b == ca) {
            cout << cc / d << endl;
            return 0;
        }
    }
    int na = ca - ac[ia - 1].first;
    int nc = cc - ac[ia - 1].second;
    ll q = ac[ia - 1].second;
    b -= ac[ia - 1].first;
    ll qq = (b - 1) / na;
    b -= na * qq;
    q += qq * nc;
    ca = cc = 0;
    if (ia == a.size()) {
        ia = 0;
        ++ca;
    }
    while(b > ca) {
        if (a[ia] == c[ic]) {
            ++ic;
            ++ia;
            if (ic == c.size()) {
                ic = 0;
                ++cc;
            }
        }
        else {
            ++ia;
        }
        if (ia == a.size()) {
            ia = 0;
            ++ca;
        }
        
    }
    q += cc;
    cout << q / d << endl;
    return 0;
}