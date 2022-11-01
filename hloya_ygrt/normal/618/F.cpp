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
const int maxn = 1e6 + 10, base = 1e9 + 7;
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
    if (s == 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2) % base;
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

ll pref1[maxn], pref2[maxn], a[maxn], b[maxn];
int paired[maxn], used[maxn];

int main()
{
    int n = input<int>();
    for (int i = 1; i <= n; i++){
        a[i] = input<ll>();
        pref1[i] = pref1[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++){
        b[i] = input<ll>();
        pref2[i] = pref2[i - 1] + b[i];
    }

    memset(used, -1, sizeof(used));
    int l2 = 0;
    for (int l1 = 0; l1 <= n; l1++){
        while (l2 <= n && pref2[l2] < pref1[l1])
            ++l2;
        ll sum1 = pref1[l1], sum2 = pref2[l2];

        // cout << sum2 - sum1 << endl;
        if (used[sum2 - sum1] != -1){
            int pairedl1 = used[sum2 - sum1];
            int pairedl2 = paired[pairedl1];
            cout << l1 - pairedl1 << endl;
            for (int i = pairedl1 + 1; i <= l1; i++)
                cout << i << ' ';
            puts("");
            cout << l2 - pairedl2 << endl;
            for (int i = pairedl2 + 1; i <= l2; i++)
                cout << i << ' ';
            bad("");
        } else {
            paired[l1] = l2;
            used[sum2 - sum1] = l1;
        }
    }
    return 0;
}