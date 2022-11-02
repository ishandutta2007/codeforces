#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int a[3003][3003];

int main()
{
    int n, x = 0, y = 0, i, j;
    long long ans = 0;
    vector <pair<int, int> > v;
    vector <int> wx, wy;
    map <int, int> mpx, mpy;
    map <int, int>::iterator it;
    queue <pair<int, int> > q;
    
    scanf("%d", &n);
    
    v.push_back(make_pair(x, y));
    mpx[x - 1] = mpx[x] = mpx[x + 1] = 0;
    mpy[y - 1] = mpy[y] = mpy[y + 1] = 0;
    
    for (i = 0; i < n; i++) {
        int z;
        char s[2];
        
        scanf("%s %d", s, &z);
        
        if (s[0] == 'L') {
            x -= z;
        } else if (s[0] == 'R') {
            x += z;
        } else if (s[0] == 'U') {
            y += z;
        } else {
            y -= z;
        }
        
        v.push_back(make_pair(x, y));
        mpx[x - 1] = mpx[x] = mpx[x + 1] = 0;
        mpy[y - 1] = mpy[y] = mpy[y + 1] = 0;
    }
    
    for (it = mpx.begin(), i = 0; it != mpx.end(); it++, i++) {
        it->second = i;
        wx.push_back(it->first);
    }
    for (it = mpy.begin(), i = 0; it != mpy.end(); it++, i++) {
        it->second = i;
        wy.push_back(it->first);
    }
    
    for (i = 0; i + 1 < v.size(); i++) {
        int x1 = mpx[v[i].first];
        int y1 = mpy[v[i].second];
        int x2 = mpx[v[i + 1].first];
        int y2 = mpy[v[i + 1].second];
        
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        
        if (x1 == x2) {
            for (j = y1; j <= y2; j++) a[x1][j] = 1;
        } else {
            for (j = x1; j <= x2; j++) a[j][y1] = 1;
        }
    }
    
    a[0][0] = 2;
    q.push(make_pair(0, 0));
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx > 3002 || ny < 0 || ny > 3002 || a[nx][ny] != 0) continue;
            
            a[nx][ny] = 2;
            q.push(make_pair(nx, ny));
        }
    }
    
    for (i = 0; i < 3003; i++) {
        for (j = 0; j < 3003; j++) {
            long long x, y;
            
            if (a[i][j] == 2) continue;
            
            x = wx[i + 1] - wx[i];
            y = wy[j + 1] - wy[j];
            
            ans += x * y;
        }
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}