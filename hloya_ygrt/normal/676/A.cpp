#include <iostream>
#include <fstream>
// #include <bits/stdc++.h>
#include <sstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <assert.h>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define fill(x) memset((x), 0, sizeof((x)))

using namespace std;

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}

template<typename T>
T dcm(string & s)
{
    T x = 0;
    for (int i = 0; i < s.size(); i++){
        x = (x * 2) + (s[i] == '1');
    }
    return x;
}

template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + int(c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b );
    } else {
        return (1LL* binpow(n, s - 1) * n);
    }
}
const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

int dist(int a, int b)
{
    return abs(a - b);
}

int main()
{
    int n;
    scanf("%d", &n);
    vi a;

    int mnpos, mxpos;
    for (int i = 0; i < n; i++){
        a.push_back(input<int>());
        if (a.back() == 1)
            mnpos = i;
        if (a.back() == n)
            mxpos = i;
    }

    int ans = dist(mnpos, mxpos);

    ans = max(ans, dist(mnpos, 0));
    ans = max(ans, dist(mnpos, n - 1));
    ans = max(ans, dist(mxpos, 0));
    ans = max(ans, dist(mxpos, n - 1));

    cout << ans;
    return 0;
}