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

template<typename ... T> void shit(T& ... x){}
template<typename ... T> void dec(T& ... x){shit(--x...);}
template<typename ... T> void inc(T& ... x){shit(++x...);}

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
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 3e2 + 10, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

vector<pair<int,int> > thisColor[maxn * maxn];
int dp[maxn][maxn], dp2[maxn][maxn];
int a[maxn][maxn];

int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int getDp(const pair<int,int> & kek)
{
    return dp[kek.f][kek.s];
}

int getDp2(const pair<int,int> & kek)
{
    return dp2[kek.f][kek.s];
}

bool cmp(const pair<int,int> & a, const pair<int, int> & b)
{
    return getDp(a) < getDp(b);
}

int px[4] = {1, 0, -1, 0};
int py[4] = {0, 1, 0, -1};

int main()
{
    memset(dp, 63, sizeof(dp));

    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                dp[i][j] = i + j;
            
            thisColor[a[i][j]].pb(mp(i, j));
        }

    int block = (n + m) / 2;
    for (int color = 2; color <= p; color++){
        if (thisColor[color].size() >= block || thisColor[color - 1].size() >= block) {

            deque<pair<int,int> > q, waitingShit;
            vector<pair<int,int> > tmp;
            for (int i = 0; i < thisColor[color - 1].size(); i++)
                tmp.pb(thisColor[color - 1][i]);
            sort(tmp.begin(), tmp.end(), cmp);

            memset(dp2, 63, sizeof(dp2));

            for (int i = 0; i < tmp.size(); i++)
                waitingShit.pb(tmp[i]);

            while (!(q.empty() && waitingShit.empty())) {
                while (q.empty() || ( (waitingShit.size())
                    && getDp(waitingShit.front()) <= getDp2(q.back()))) {
                    if (q.empty() && waitingShit.empty())
                        break;
                    pair<int,int> newComer = waitingShit.front();

                    if (dp2[newComer.f][newComer.s] > getDp(newComer)){
                        q.push_back(newComer);
                        dp2[newComer.f][newComer.s] = getDp(newComer);
                    }
                    waitingShit.pop_front();
                }

                if (q.empty() && waitingShit.empty())
                    break;
                int x = q.front().f, y = q.front().s;
                // cerr << x << ' ' << y << ' ' << getDp2(mp(x, y)) << endl;
                q.pop_front();

                for (int i = 0; i < 4; i++) {
                    int nx = x + px[i], ny = y + py[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m
                        && dp2[nx][ny] > dp2[x][y] + 1) {
                        q.push_back(mp(nx, ny));
                        dp2[nx][ny] = dp2[x][y] + 1;
                    }
                }
            }
            for (int i = 0; i < thisColor[color].size(); i++) {
                int x = thisColor[color][i].f, y = thisColor[color][i].s;
                dp[x][y] = dp2[x][y];
                // cerr << dp[x][y] << endl;
            }
            // return 0;
        } else {
            for (int i = 0; i < thisColor[color].size(); i++) 
                for (int j = 0; j < thisColor[color - 1].size(); j++) {
                    int x1 = thisColor[color][i].f, y1 = thisColor[color][i].s;
                    int x2 = thisColor[color - 1][j].f, y2 = thisColor[color - 1][j].s;
                    
                    dp[x1][y1] = min(dp[x1][y1], dp[x2][y2] + dist(x1, y1, x2, y2));
                }
        }
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++){
        //         fprintf(stderr, "%010d ", dp[i][j]);
        //     }
        //     cerr << endl;
        // }
        // cerr << color << endl << endl;
    }
    int ans = inf;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == p){
                ans = min(ans, dp[i][j]);
            }
    cout << ans;
    return 0;
}