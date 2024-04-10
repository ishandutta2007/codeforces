#include <iostream>
#include <fstream>
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
#include <tuple>
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

const int inf = 2e9;
const double eps = 1e-6;
const int maxn = 2e5 + 5, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

void bad(string mes = "Impossible"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % 2);
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}


template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
    while (c == ' ' || c == '\n')
        c = getchar();
    if (c == '-')
        m = -1, c = getchar();
    while (c != ' ' && c != '\n')
        ans = ans * 10 + c - '0', c = getchar();
    return ans * m;
}

template<typename T>
T binpow(T n, T s)
{
    if (s == 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2) % base;
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

template<typename T>
T sqr(T x)
{
    return x * x;
}

int n, a[maxn], b[maxn], c[maxn];
pair<int,int> ans = mp(0, 0);
map<int,int> cnt;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
        cnt[a[i]]++;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d", b + i);
    }

    for (int i = 0; i < m; i++){
        scanf("%d", c + i);
    }

    for (int i = 0; i < m; i++){
        int cur1, cur2;
        cur1 = cnt[b[i]], cur2 = cnt[c[i]];
        ans = max(ans, mp(cur1, cur2));
    }
    for (int i = 0; i < m; i++){
        int cur1, cur2;
        cur1 = cnt[b[i]], cur2 = cnt[c[i]];
        if (mp(cur1, cur2) == ans)
            return cout << i + 1, 0;
    }

    return 0;
}