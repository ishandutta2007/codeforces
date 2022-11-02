#include <iostream>
#include <string>
#include <deque>
#include <utility>
using namespace std;

string s[2009];
deque<pair<int, int> > d;
int ds[2009][2009], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m, sy, sx, l, r;
    cin>>n>>m>>sy>>sx>>l>>r;
    sx--; sy--;
    for (int i = 0; i < n; i++)
        cin>>s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ds[i][j] = 1000000000;
    ds[sy][sx] = 0;
    d.push_front(make_pair(sx, sy));
    while (!d.empty()){
        int x = d.front().first, y = d.front().second; d.pop_front();
        for (int i = 0; i < 4; i++){
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n || s[ty][tx] == '*') continue;
            int tr = (int)(i == 0);
            if (ds[ty][tx] > ds[y][x] + tr){
                ds[ty][tx] = ds[y][x] + tr;
                if (tr == 0)
                    d.push_front(make_pair(tx, ty));
                else
                    d.push_back(make_pair(tx, ty));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '.' && ds[i][j] <= l && j - sx + ds[i][j] <= r)
                ans++;
    cout<<ans<<'\n';
    return 0;
}