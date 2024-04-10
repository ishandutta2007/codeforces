#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <int, map<int, int> > mp, mp2;
map <int, vector <pair<int, int> > > mp3, mp4;
map <int, int> mp5, mp6;
int a[200001];
int sum[200001];

int main()
{
    int n, m, k, ans = 0, i;
    map <int, map<int, int> >::iterator it;
    map <int, int>::iterator it2;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        if (y1 == y2) {
            mp[y1][x1] = 0;
            mp[y1][x2] = 0;
            
            mp3[y1].push_back(make_pair(min(x1, x2), max(x1, x2)));
        } else {
            mp2[x1][y1] = 0;
            mp2[x1][y2] = 0;
            
            mp4[x1].push_back(make_pair(min(y1, y2), max(y1, y2)));
        }
    }
    
    if ((m - mp.size() - 1) % 2 == 1) ans ^= n;
    if ((n - mp2.size() - 1) % 2 == 1) ans ^= m;
    
    for (it = mp.begin(); it != mp.end(); it++) {
        int x = 0;
        
        for (it2 = it->second.begin(), i = 0; it2 != it->second.end(); it2++, i++) {
            it2->second = i;
            a[i] = it2->first;
        }
        
        for (i = 0; i < it->second.size(); i++) sum[i] = 0;
        
        for (i = 0; i < mp3[it->first].size(); i++) {
            sum[it->second[mp3[it->first][i].first]]++;
            sum[it->second[mp3[it->first][i].second]]--;
        }
        
        for (i = 1; i < it->second.size(); i++) sum[i] += sum[i - 1];
        
        for (i = 0; i < it->second.size() - 1; i++) {
            if (sum[i] == 0) x += a[i + 1] - a[i];
        }
        
        x += a[0] + n - a[it->second.size() - 1];
        
        mp5[it->first] = x;
        
        ans ^= x;
    }
    
    for (it = mp2.begin(); it != mp2.end(); it++) {
        int x = 0;
        
        for (it2 = it->second.begin(), i = 0; it2 != it->second.end(); it2++, i++) {
            it2->second = i;
            a[i] = it2->first;
        }
        
        for (i = 0; i < it->second.size(); i++) sum[i] = 0;
        
        for (i = 0; i < mp4[it->first].size(); i++) {
            sum[it->second[mp4[it->first][i].first]]++;
            sum[it->second[mp4[it->first][i].second]]--;
        }
        
        for (i = 1; i < it->second.size(); i++) sum[i] += sum[i - 1];
        
        for (i = 0; i < it->second.size() - 1; i++) {
            if (sum[i] == 0) x += a[i + 1] - a[i];
        }
        
        x += a[0] + m - a[it->second.size() - 1];
        
        mp6[it->first] = x;
        
        ans ^= x;
    }
    
    if (ans == 0) {
        puts("SECOND");
    } else {
        puts("FIRST");
        
        if ((ans ^ n) < n) {
            for (i = 1; i < m; i++) {
                if (mp.count(i) == 0) {
                    printf("%d %d %d %d\n", 0, i, n - (ans ^ n), i);
                    
                    return 0;
                }
            }
        }
        
        if ((ans ^ m) < m) {
            for (i = 1; i < n; i++) {
                if (mp2.count(i) == 0) {
                    printf("%d %d %d %d\n", i, 0, i, m - (ans ^ m));
                    
                    return 0;
                }
            }
        }
        
        for (it = mp.begin(); it != mp.end(); it++) {
            if ((ans ^ mp5[it->first]) < mp5[it->first]) {
                int x = 0;
                
                ans = mp5[it->first] - (ans ^ mp5[it->first]);
                
                for (it2 = it->second.begin(), i = 0; it2 != it->second.end(); it2++, i++) {
                    a[i] = it2->first;
                }
                
                for (i = 0; i < it->second.size(); i++) sum[i] = 0;
                
                for (i = 0; i < mp3[it->first].size(); i++) {
                    sum[it->second[mp3[it->first][i].first]]++;
                    sum[it->second[mp3[it->first][i].second]]--;
                }
                
                for (i = 1; i < it->second.size(); i++) sum[i] += sum[i - 1];
                
                for (i = 0; i < it->second.size() - 1; i++) {
                    if (sum[i] == 0) {
                        if (x + a[i + 1] - a[i] >= ans) {
                            printf("%d %d %d %d\n", a[0], it->first, ans - x + a[i], it->first);
                            
                            return 0;
                        }
                        
                        x += a[i + 1] - a[i];
                    }
                }
                
                if (x + a[0] >= ans) {
                    printf("%d %d %d %d\n", a[0] + x - ans, it->first, a[it->second.size() - 1], it->first);
                } else {
                    printf("%d %d %d %d\n", 0, it->first, ans + a[it->second.size() - 1] - a[0] - x, it->first);
                }
                
                return 0;
            }
        }
        
        for (it = mp2.begin(); it != mp2.end(); it++) {
            if ((ans ^ mp6[it->first]) < mp6[it->first]) {
                int x = 0;
                
                ans = mp6[it->first] - (ans ^ mp6[it->first]);
                
                for (it2 = it->second.begin(), i = 0; it2 != it->second.end(); it2++, i++) {
                    a[i] = it2->first;
                }
                
                for (i = 0; i < it->second.size(); i++) sum[i] = 0;
                
                for (i = 0; i < mp4[it->first].size(); i++) {
                    sum[it->second[mp4[it->first][i].first]]++;
                    sum[it->second[mp4[it->first][i].second]]--;
                }
                
                for (i = 1; i < it->second.size(); i++) sum[i] += sum[i - 1];
                
                for (i = 0; i < it->second.size() - 1; i++) {
                    if (sum[i] == 0) {
                        if (x + a[i + 1] - a[i] >= ans) {
                            printf("%d %d %d %d\n", it->first, a[0], it->first, ans - x + a[i]);
                            
                            return 0;
                        }
                        
                        x += a[i + 1] - a[i];
                    }
                }
                
                if (x + a[0] >= ans) {
                    printf("%d %d %d %d\n", it->first, a[0] + x - ans, it->first, a[it->second.size() - 1]);
                } else {
                    printf("%d %d %d %d\n", it->first, 0, it->first, ans + a[it->second.size() - 1] - a[0] - x);
                }
                
                return 0;
            }
        }
    }
    
    return 0;
}