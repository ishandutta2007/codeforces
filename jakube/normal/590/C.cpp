#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <limits.h>

using namespace std;

#define lld long long
#define llu unsigned long long
#define all(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const lld MOD = 1000000007ll;

template<typename T>
T read()
{
    T tmp;
    cin >> tmp;
    return tmp;
}
#define readi read<int>
#define readl read<lld>

template<typename T>
vector<T> reads(int count)
{
    vector<T> values;
    values.reserve(count);
    for (int i = 0; i < count; i++)
        values.push_back(read<T>());
    return values;
}
#define readsi reads<int>
#define readsl reads<lld>


int n, m;
vector<vector<char>> board;
vector<vector<int>> ds(3, vector<int>(3, INT_MAX));
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};

vector<vector<int>> floodfill(int coord)
{
    vector<vector<int>> d(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    FOR(i, n)
    {
        FOR(j, m)
        {
            char c = board[i][j];
            if (c == '1' + coord)
            {
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (q.size())
    {
        pair<int, int> p = q.front();
        q.pop();

        int i = p.first;
        int j = p.second;

        FOR(dir, 4)
        {
            int i2 = i + x[dir];
            int j2 = j + y[dir];

            if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m) {
                if (board[i2][j2] != '#' && d[i][j] + 1 < d[i2][j2]) {
                    d[i2][j2] = d[i][j] + 1;
                    q.push(make_pair(i2, j2));
                }
                if (board[i2][j2] == '1' + ((coord + 1)%3) || board[i2][j2] == '1' + ((coord + 2)%3))
                {
                    if (d[i][j] < ds[coord][board[i2][j2] - '1'])
                        ds[coord][board[i2][j2] - '1'] = d[i][j];

                }
            }
        }
    }
    return d;
}


int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    n = readi();
    m = readi();

    FOR(i, n)
    {
        vector<char> b;
        string s = read<string>();
        int j = 0;
        for (char c: s) {
            b.push_back(c);
            j++;
        }
        board.push_back(b);
    }

    vector<vector<vector<int>>> d;

    FOR(coord, 3)
        d.push_back(floodfill(coord));

    // case 1, connected via 2 lines (e.g 1-2, 2-3)
    int best = INT_MAX;
    FOR(coord, 3)
    {
        if (ds[coord][(coord + 1)  % 3] < INT_MAX &&
            ds[coord][(coord + 2)  % 3] < INT_MAX)
        {
            int sum = ds[coord][(coord + 1)  % 3] + ds[coord][(coord + 2)  % 3];
            if (best > sum)
                best = sum;
        }
    }

    // case 2, all streets meet in one point
    FOR(i, n)
        FOR(j, m)
        {
            if (d[0][i][j] < INT_MAX && d[1][i][j] < INT_MAX && d[2][i][j] < INT_MAX)
            {
                int sum = d[0][i][j] + d[1][i][j] + d[2][i][j] - 2;
                if (best > sum)
                    best = sum;

            }
        }


    if (best < INT_MAX)
        cout << best;
    else
        cout << -1;



}