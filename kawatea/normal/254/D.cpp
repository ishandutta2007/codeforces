#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int f[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m, d, i, j, k;
    char s[1000][1001];
    vector <pair<int, int> > v, w;
    queue <pair<int, pair<int, int> > > q;
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d %d %d", &n, &m, &d);
    
    for (i = 0; i < n; i++) fscanf(fp, "%s", s[i]);
    
    fclose(fp);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'R') v.push_back(make_pair(i, j));
        }
    }
    
    if (v.size() > 290) {
        fp = fopen("output.txt", "w");
        
        fprintf(fp, "-1\n");
        
        fclose(fp);
        
        return 0;
    }
    
    f[v[0].first][v[0].second] = 1;
    q.push(make_pair(0, make_pair(v[0].first, v[0].second)));
    
    while (!q.empty()) {
        int c = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        
        q.pop();
        
        w.push_back(make_pair(x, y));
        
        if (c == d) continue;
        
        for (i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (s[nx][ny] == 'X' || f[nx][ny] == 1) continue;
            
            f[nx][ny] = 1;
            q.push(make_pair(c + 1, make_pair(nx, ny)));
        }
    }
    
    for (i = 0; i < w.size(); i++) {
        vector <pair<int, int> > z;
        queue <pair<int, pair<int, pair<int, int> > > > que;
        map <int, int> mp[1000];
        map <pair<int, int>, int> mp2[145];
        map <int, int>::iterator it;
        
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                f[j][k] = 0;
            }
        }
        
        f[w[i].first][w[i].second] = 1;
        q.push(make_pair(0, make_pair(w[i].first, w[i].second)));
        
        while (!q.empty()) {
            int c = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            
            q.pop();
            
            mp[x][y] = 1;
            
            if (c == d) continue;
            
            for (j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (s[nx][ny] == 'X' || f[nx][ny] == 1) continue;
                
                f[nx][ny] = 1;
                q.push(make_pair(c + 1, make_pair(nx, ny)));
            }
        }
        
        for (j = 0; j < v.size(); j++) {
            if (!mp[v[j].first].count(v[j].second)) z.push_back(make_pair(v[j].first, v[j].second));
        }
        
        if (z.size() > 145) continue;
        
        if (z.size() == 0) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < m; k++) {
                    if (s[j][k] == 'X') continue;
                    
                    if (j == w[i].first && k == w[i].second) continue;
                    
                    fp = fopen("output.txt", "w");
                    
                    fprintf(fp, "%d %d %d %d\n", w[i].first + 1, w[i].second + 1, j + 1, k + 1);
                    
                    fclose(fp);
                    
                    return 0;
                }
            }
        }
        
        for (j = 0; j < n; j++) mp[j].clear();
        
        for (j = 0; j < z.size(); j++) {
            mp2[j][make_pair(z[j].first, z[j].second)] = 1;
            que.push(make_pair(0, make_pair(j, make_pair(z[j].first, z[j].second))));
        }
        
        while (!que.empty()) {
            int c = que.front().first;
            int t = que.front().second.first;
            int x = que.front().second.second.first;
            int y = que.front().second.second.second;
            
            que.pop();
            
            mp[x][y]++;
            
            if (c == d) continue;
            
            for (j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if (s[nx][ny] == 'X' || mp2[t].count(make_pair(nx, ny))) continue;
                
                mp2[t][make_pair(nx, ny)] = 1;
                que.push(make_pair(c + 1, make_pair(t, make_pair(nx, ny))));
            }
        }
        
        for (j = 0; j < n; j++) {
            for (it = mp[j].begin(); it != mp[j].end(); it++) {
                if (it->second == z.size()) {
                    fp = fopen("output.txt", "w");
                    
                    fprintf(fp, "%d %d %d %d\n", w[i].first + 1, w[i].second + 1, j + 1, it->first + 1);
                    
                    fclose(fp);
                    
                    return 0;
                }
            }
        }
    }
    
    fp = fopen("output.txt", "w");
    
    fprintf(fp, "-1\n");
    
    fclose(fp);
    
    return 0;
}