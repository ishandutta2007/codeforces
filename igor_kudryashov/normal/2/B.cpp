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

const int nmax = 1005;

int n, m;
int z1[nmax][nmax], z2[nmax][nmax];
int sour1[nmax][nmax], sour2[nmax][nmax];
bool p1[nmax][nmax], p2[nmax][nmax];

inline int twos (int a) {
    if (a == 0) return 0;
    int kol = 0;
    while ((a & 1) == 0) {
        kol++;
        a >>= 1;
    }
    return kol;
}

inline int fif (int a) {
    if (a == 0) return 0;
    int kol = 0;
    while (a % 5 == 0) {
        kol++;
        a /= 5;
    }
    return kol;
}

int nuli, nulj;

int main()
{
    cin >> n;
    //cin >> m;
    m = n;
    bool hasnull = false;

    forn(i, n)
        forn(j, m) {
            int a;
            scanf("%d", &a);
            if (a == 0) {
                hasnull = true;
                nuli = i;
                nulj = j;
            }
            int t2 = twos(a), t5 = fif(a);
            z1[i][j] = t2, z2[i][j] = t5;
            sour1[i][j] = t2, sour2[i][j] = t5;
        }
    for1(i, n - 1) {
        z1[0][i] += z1[0][i - 1];
        z2[0][i] += z2[0][i - 1];
        z1[i][0] += z1[i - 1][0];
        p1[i][0] = true;
        z2[i][0] += z2[i - 1][0];
        p2[i][0] = true;        
    }

    for1(i, n - 1)
        for1(j, m - 1) {
            if (z1[i - 1][j] < z1[i][j - 1]) {
                z1[i][j] += z1[i - 1][j];
                p1[i][j] = true;
            } else z1[i][j] += z1[i][j - 1];
            if (z2[i - 1][j] < z2[i][j - 1]) {
                z2[i][j] += z2[i - 1][j];
                p2[i][j] = true;
            } else z2[i][j] += z2[i][j - 1];
        }
    
    int firans = INF;
    string fir = "";
    int id = n - 1, jd = m - 1, kol = sour2[0][0];
    while (id != 0 || jd != 0) {
        kol += sour2[id][jd];
        if (p1[id][jd]) {
            fir.push_back('D');
            id--;
        } else {
            fir.push_back('R');
            jd--;
        }
    }
    firans = min(z1[n - 1][m - 1], kol);
    reverse(fir.begin(), fir.end());

    int secans = INF;
    string sec = "";
    id = n - 1, jd = m - 1, kol = sour1[0][0];
    while (id != 0 || jd != 0) {
        kol += sour1[id][jd];
        if (p2[id][jd]) {
            sec.push_back('D');
            id--;
        } else {
            sec.push_back('R');
            jd--;
        }       
    }
    secans = min(z2[n - 1][m - 1], kol);
    reverse(sec.begin(), sec.end());
    if (firans > secans) {
        swap(firans, secans);
        swap(fir, sec);
    }
    if (firans > 1 && hasnull) {
        string res = "";
        forn(i, nuli) res.push_back('D');
        forn(i, n - 1) res.push_back('R');
        for (int i = nuli; i < n - 1; i++) res.push_back('D');
        cout << 1 << endl;
        cout << res << endl;
    } else {
        cout << firans << endl;
        cout << fir << endl;
    }
    return 0;
}