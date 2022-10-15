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
typedef pair<char, char> pcc;

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
//const long double eps = 1e-5;
//const int INF = 50000;
//const int N = 1000 * 1000 + 10;
//const ll mod = 1000 * 1000 * 1000 + 7;;


int main() {
    //std::ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, t;
    int a[401][401];
    for (int i = 0; i < 401; ++i)
        for (int j = 0; j < 401; ++j)
            a[i][j] = 0;
    scanf("%d %d", &n, &t);
    a[200][200] = n;
    queue<pii> q;
    q.push(make_pair(200, 200));
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        if (a[x.first][x.second] < 4)
            continue;
        int add = a[x.first][x.second] / 4;
        a[x.first][x.second] %= 4;
        for (int i = 0; i < 4; ++i) {
            pii y;
            if (i == 0)
                y = make_pair(x.first - 1, x.second);
            if (i == 1)
                y = make_pair(x.first + 1, x.second);
            if (i == 2)
                y = make_pair(x.first, x.second - 1);
            if (i == 3)
                y = make_pair(x.first, x.second + 1);
            a[y.first][y.second] += add;
            if (a[y.first][y.second] >= 4)
                q.push(y);
        }
    }
    for (int i = 0; i < t; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        x += 200, y += 200;
        if ((x >= 401) || (x < 0) || (y < 0) || (y >= 401))
            printf("%d\n", 0);
        else
            printf("%d\n", a[x][y]);
    }
    return 0;
}