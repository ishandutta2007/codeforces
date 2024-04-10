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

const int inf = 2e9;
const double eps = 1e-9;
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

struct Query
{
    int l, r, it;
    Query(){}
    Query(int l, int r, int it):l(l), r(r), it(it){}

    bool operator < (const Query & T) const 
    {
        return (r < T.r) || (r == T.r && it < T.it);
    }
};

const int block = 400;

vector<Query> query[maxn / block + 10];
ll answers[maxn];
int cnt[maxn], a[maxn];

void update(ll & curans, int cur, int plusOrMinus = 1)
{
    curans -= (ll)cnt[cur] * cnt[cur] * cur;
    cnt[cur] += plusOrMinus;
    curans += (ll)cnt[cur] * cnt[cur] * cur;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < t; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;

        query[l / block].push_back(Query(l, r, i));
    }

    for (int i = 0; i <= (n - 1) / block; i++){
        sort(query[i].begin(), query[i].end());
        if (query[i].empty())
            continue;
        ll curans = 0;
        memset(cnt, 0, sizeof(cnt));

        int left = query[i][0].l, right = query[i][0].r, pos = query[i][0].it;
        for (int j = left; j <= right; j++){
            int cur = a[j];
            update(curans, cur);
        }
        answers[pos] = curans;

        for (int j = 1; j < query[i].size(); j++){
            int newLeft = query[i][j].l, newRight = query[i][j].r;
                pos = query[i][j].it;   

            while (left > newLeft){
                left--;
                int cur = a[left];
                update(curans, cur);
            }
            while (left < newLeft){
                int cur = a[left];
                update(curans, cur, -1);
                left++;
            }
            while (right < newRight){
                right++;
                int cur = a[right];
                update(curans, cur);
            }

            answers[pos] = curans;
        }
    }

    for (int i = 0; i < t; i++)
        printf("%I64d\n", answers[i]);
    return 0;
}