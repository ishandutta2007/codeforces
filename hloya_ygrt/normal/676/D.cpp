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
const int maxn = 1e3 + 10, base = 1e9 + 7;
const int sigm = 26;
const ll llinf = 1e18;

struct Room
{
    vector<char> haveDoor;

    Room(){
        haveDoor = vector<char>(4, 0);
    }
    Room(vector<char> haveDoor):haveDoor(haveDoor){}

    Room rotated()
    {
        vector<char> v = haveDoor;
        rotate(v.rbegin(), v.rbegin() + 1, v.rend());
        return Room(v);
    }

    void print()
    {
        for (int i = 0; i < 4; i++)
            cout << int(haveDoor[i]);
        cout << endl;
    }

    bool g(int r)
    {
        assert(r >= 0 && r < 4);
        return haveDoor[r];
    }
};

Room basic[maxn][maxn][4];
ll dist[maxn][maxn][4];

    int n, m;
bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){

            for (int k = 0; k < 4; k++)
                dist[i][j][k] = llinf;

            char c = endl;
            while (c == endl)
                c = getchar();
            vector<char> cur(4, 0);

            if (c == '+'){
                cur[0] = cur[1] = cur[2] = cur[3] = 1;
            }
            if (c == '-'){
                cur[3] = cur[1] = 1;
            }
            if (c == '|'){
                cur[0] = cur[2] = 1;
            }
            if (c == '^'){
                cur[0] = 1;
            }
            if (c == '>'){
                cur[1] = 1;
            }
            if (c == '<'){
                cur[3] = 1;
            }
            if (c == 'v'){
                cur[2] = 1;
            }
            if (c == 'L'){
                cur[0] = cur[1] = cur[2] = 1;
            }
            if (c == 'R'){
                cur[0] = cur[2] = cur[3] = 1;
            }
            if (c == 'U'){
                cur[1] = cur[2] = cur[3] = 1;
            }
            if (c == 'D'){
                cur[0] = cur[1] = cur[3] = 1;
            }
            basic[i][j][0] = Room(cur);

            for (int k = 1; k < 4; k++)
                basic[i][j][k] = basic[i][j][k - 1].rotated();
        }

    // basic[0][0][0].print();
    getchar();
    int x1, y1;
    int x2, y2;
    scanf("%d %d", &x1, &y1);

    scanf("%d %d", &x2, &y2);
    x1--, y1--;
    x2--, y2--;

    dist[x1][y1][0] = 0;
    queue<pair<pii, int> > q;
    q.push(mp(mp(x1, y1), 0));

    while (!q.empty()){
        int x = q.front().f.f, y = q.front().f.s;
        int r = q.front().s;

        q.pop();

        if (dist[x][y][(r + 1) % 4] > dist[x][y][r] + 1){
            dist[x][y][(r + 1) % 4] = dist[x][y][r] + 1;
            q.push(mp(mp(x, y), (r + 1) % 4));
        }

        if (valid(x + 1, y) && (basic[x][y][r].g(2) & basic[x + 1][y][r].g(0)) &&
            dist[x + 1][y][r] > dist[x][y][r] + 1){
            dist[x + 1][y][r] = dist[x][y][r] + 1;
            q.push(mp(mp(x + 1, y), r));
        }
        if (valid(x - 1, y) && (basic[x][y][r].g(0) & basic[x - 1][y][r].g(2)) &&
            dist[x - 1][y][r] > dist[x][y][r] + 1){
            dist[x - 1][y][r] = dist[x][y][r] + 1;
            q.push(mp(mp(x - 1, y), r));
        }
        if (valid(x, y + 1) && (basic[x][y][r].g(1) & basic[x][y + 1][r].g(3)) &&
            dist[x][y + 1][r] > dist[x][y][r] + 1){
            dist[x][y + 1][r] = dist[x][y][r] + 1;
            q.push(mp(mp(x, y + 1), r));
        }
        if (valid(x, y - 1) && (basic[x][y][r].g(3) & basic[x][y - 1][r].g(1)) &&
            dist[x][y - 1][r] > dist[x][y][r] + 1){
            dist[x][y - 1][r] = dist[x][y][r] + 1;
            q.push(mp(mp(x, y - 1), r));
        }      
    }

    ll mn = llinf;

    for (int i = 0; i < 4; i++){
        mn = min(mn, dist[x2][y2][i]);
    }
    if (mn == llinf)
        bad("-1");
    cout << mn;
    return 0;
}