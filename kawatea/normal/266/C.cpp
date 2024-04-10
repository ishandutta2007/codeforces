#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j, k;
    map <int, int> mp[1000];
    map <int, int> mp2[1000];
    vector <pair<int, pair<int, int> > > v;
    map <int, int>::iterator it;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        mp[x][y]++;
        mp2[y][x]++;
    }
    
    for (i = 0; i < n / 2; i++) {
        int m1 = 0, m2 = 0, p, q;
        
        for (j = i; j < n - i; j++) {
            if (mp[j].size() == 0) break;
        }
        
        if (i != j) {
            v.push_back(make_pair(1, make_pair(i + 1, j + 1)));
            
            swap(mp[i], mp[j]);
            
            for (it = mp[j].begin(); it != mp[j].end(); it++) {
                mp2[it->first].erase(i);
                mp2[it->first][j]++;
            }
        }
        
        for (j = i; j < n - i; j++) {
            if (mp2[j].size() == 0) break;
        }
        
        if (n - i - 1 != j) {
            v.push_back(make_pair(2, make_pair(n - i, j + 1)));
            
            swap(mp2[n - i - 1], mp2[j]);
            
            for (it = mp2[j].begin(); it != mp2[j].end(); it++) {
                mp[it->first].erase(n - i - 1);
                mp[it->first][j]++;
            }
        }
        
        for (j = i; j < n - i; j++) {
            if (mp[j].size() > m1) {
                m1 = mp[j].size();
                p = j;
            }
            
            if (mp2[j].size() > m2) {
                m2 = mp2[j].size();
                q = j;
            }
        }
        
        if (m1 <= 1 && m2 <= 1) {
            for (j = i + 1; j < n - i; j++) {
                for (it = mp[j].begin(); it != mp[j].end(); it++) {
                    int x = it->first;
                    
                    if (x == j - 1) continue;
                    
                    v.push_back(make_pair(2, make_pair(x + 1, j)));
                    
                    swap(mp2[x], mp2[j - 1]);
                    
                    if (!mp2[x].empty()) {
                        int y = mp2[x].begin()->first;
                        
                        mp[y].erase(j - 1);
                        mp[y][x]++;
                    }
                }
            }
            
            break;
        } else if (m1 > 1) {
            if (n - i - 1 != p) {
                v.push_back(make_pair(1, make_pair(n - i, p + 1)));
                
                swap(mp[n - i - 1], mp[p]);
                
                for (it = mp[p].begin(); it != mp[p].end(); it++) {
                    mp2[it->first][n - i - 1]--;
                    
                    if (mp2[it->first][n - i - 1] == 0) mp2[it->first].erase(n - i - 1);
                    
                    mp2[it->first][p]++;
                }
                
                for (it = mp[n - i - 1].begin(); it != mp[n - i - 1].end(); it++) {
                    mp2[it->first][p]--;
                    
                    if (mp2[it->first][p] == 0) mp2[it->first].erase(p);
                    
                    mp2[it->first][n - i - 1]++;
                }
            }
        } else {
            if (i != q) {
                v.push_back(make_pair(2, make_pair(i + 1, q + 1)));
                
                swap(mp2[i], mp2[q]);
                
                for (it = mp2[q].begin(); it != mp2[q].end(); it++) {
                    mp[it->first][i]--;
                    
                    if (mp[it->first][i] == 0) mp[it->first].erase(i);
                    
                    mp[it->first][q]++;
                }
                
                for (it = mp2[i].begin(); it != mp2[i].end(); it++) {
                    mp[it->first][q]--;
                    
                    if (mp[it->first][q] == 0) mp[it->first].erase(q);
                    
                    mp[it->first][i]++;
                }
            }
        }
        
        mp[i].clear();
        mp[n - i - 1].clear();
        mp2[i].clear();
        mp2[n - i - 1].clear();
        
        for (j = i; j < n - i; j++) mp[j].erase(i);
        for (j = i; j < n - i; j++) mp[j].erase(n - i - 1);
        for (j = i; j < n - i; j++) mp2[j].erase(i);
        for (j = i; j < n - i; j++) mp2[j].erase(n - i - 1);
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d %d\n", v[i].first, v[i].second.first, v[i].second.second);
    
    return 0;
}