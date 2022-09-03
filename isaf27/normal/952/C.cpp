//isaf27

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-10;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int MAX_LOG = 19;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

int n;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> st = a;
    vector<int> b;
    while (a.size() > 1)
    {
        for (int i = 1; i < (int)a.size() - 1; i++)
            if (abs(a[i + 1] - a[i]) >= 2 && abs(a[i + 2] - a[i]) >= 2)
            {
                cout << "NO";
                return 0;
            }
        vector<int> nw = a;
        for (int i = 0; i < (int)a.size() - 1; i++)
            if (abs(a[i + 1] - a[i]) >= 2)
            {
                if (a[i + 1] > a[i])
                    nw[i]++;
                else
                    nw[i + 1]++;
            }
        int t = 0;
        for (int i = 0; i < nw.size(); i++)
            if (nw[t] < nw[i])
                t = i;
        b.push_back(nw[t]);
        a.clear();
        for (int i = 0; i < t; i++)
            a.push_back(nw[i]);
        for (int i = t + 1; i < nw.size(); i++)
            a.push_back(nw[i]);
    }
    b.push_back(a[0]);
    sort(st.begin(), st.end());
    bool ch = true;
    for (int i = 0; i < n; i++)
        ch &= (st[i] == b[i]);
    if (ch)
    {
        cout << "YES";
        return 0;
    }
    reverse(st.begin(), st.end());
    ch = true;
    for (int i = 0; i < n; i++)
        ch &= (st[i] == b[i]);
    if (ch)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}