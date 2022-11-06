#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <map>
#include <string>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

#define forn(i, n) for (int i = 0; i < int (n); i++)
#define for1(i, n) for (int i = 1; i <= int (n); i++)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define sqr(a) ((a) * (a))

typedef long long li;
typedef pair <int, int> pt;
const int INF = 1e9;
const int NMAX = 1e4;
const double EPS = 1e-9;

int kol, n;
int k;
int rg[150][150];
int xc, yc;
bool used[150][150];

int sum (int k) {
    return k * (k + 1) / 2;
}

vector <int> get (int k) {
    int res = INF;
    int x = -1, y = -1;
    forn(i, n)
        forn(j, n) {
            int tmp = 0;
            for (int h = j; h < j + k; h++) {
                if (h >= n) {
                    tmp = -1;
                    break;
                }
                if (used[i][h]) {
                    tmp = -1;
                    break;
                } else {
                    tmp += abs(i - xc);
                    tmp += abs(h - yc);
                }
            }
            if (tmp < 0) continue;
            if (tmp < res) {
                res = tmp;
                x = i;
                y = j;
            }
        }
    vector <int> ans;
    if (x < 0) {
        ans.push_back(-1); 
        return ans;
    } else {
        ans.push_back(x + 1);
        ans.push_back(y + 1);
        ans.push_back(y + k);
    }
    for (int j = y; j < y + k; j++) used[x][j] = true;
    return ans;
}

int main()
{
    cin >> kol >> n;
    xc = (n) / 2;
    yc = (n) / 2;
    forn(i, kol) {
        cin >> k;
        vector <int> t = get(k);
        forn(j, t.size()) printf("%d ", t[j]);
        cout << endl;
    }
    return 0;
}