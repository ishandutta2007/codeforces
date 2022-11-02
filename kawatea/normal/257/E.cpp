#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long ans[100000];
vector <pair<int, pair<int, pair<int, int> > > > v;
vector <int> w[100001];
vector <pair<int, int> > z[100001];
set <int> s;

int main()
{
    int n, m, c = 0, p = 0, q = 0, r = 1, i;
    long long t = 0;
    set <int>::iterator it;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x, y, z;
        
        scanf("%d %d %d", &x, &y, &z);
        
        v.push_back(make_pair(x, make_pair(y, make_pair(z, i))));
    }
    
    sort(v.begin(), v.end());
    
    while (1) {
        if (s.empty()) {
            if (c == v.size()) break;
            
            t = v[c].first;
            
            if (v[c].second.first == r) {
                w[v[c].second.second.first].push_back(v[c].second.second.second);
                
                s.insert(v[c].second.second.first);
                
                if (v[c].second.second.first > r) {
                    p++;
                } else {
                    q++;
                }
            } else {
                z[v[c].second.first].push_back(make_pair(v[c].second.second.first, v[c].second.second.second));
                
                s.insert(v[c].second.first);
                
                if (v[c].second.first > r) {
                    p++;
                } else {
                    q++;
                }
            }
            
            c++;
        } else {
            if (p >= q) {
                it = s.lower_bound(r);
                
                if (c == v.size() || t + *it - r <= v[c].first) {
                    t += *it - r;
                    r = *it;
                    
                    p -= w[r].size() + z[r].size();
                    
                    for (i = 0; i < w[r].size(); i++) ans[w[r][i]] = t;
                    
                    for (i = 0; i < z[r].size(); i++) {
                        w[z[r][i].first].push_back(z[r][i].second);
                        
                        s.insert(z[r][i].first);
                        
                        if (z[r][i].first > r) {
                            p++;
                        } else {
                            q++;
                        }
                    }
                    
                    w[r].clear();
                    z[r].clear();
                    
                    s.erase(r);
                } else {
                    r += v[c].first - t;
                    t = v[c].first;
                    
                    if (v[c].second.first == r) {
                        w[v[c].second.second.first].push_back(v[c].second.second.second);
                        
                        s.insert(v[c].second.second.first);
                        
                        if (v[c].second.second.first > r) {
                            p++;
                        } else {
                            q++;
                        }
                    } else {
                        z[v[c].second.first].push_back(make_pair(v[c].second.second.first, v[c].second.second.second));
                        
                        s.insert(v[c].second.first);
                        
                        if (v[c].second.first > r) {
                            p++;
                        } else {
                            q++;
                        }
                    }
                    
                    c++;
                }
            } else {
                it = s.lower_bound(r);
                
                it--;
                
                if (c == v.size() || t + r - *it <= v[c].first) {
                    t += r - *it;
                    r = *it;
                    
                    q -= w[r].size() + z[r].size();
                    
                    for (i = 0; i < w[r].size(); i++) ans[w[r][i]] = t;
                    
                    for (i = 0; i < z[r].size(); i++) {
                        w[z[r][i].first].push_back(z[r][i].second);
                        
                        s.insert(z[r][i].first);
                        
                        if (z[r][i].first > r) {
                            p++;
                        } else {
                            q++;
                        }
                    }
                    
                    w[r].clear();
                    z[r].clear();
                    
                    s.erase(r);
                } else {
                    r -= v[c].first - t;
                    t = v[c].first;
                    
                    if (v[c].second.first == r) {
                        w[v[c].second.second.first].push_back(v[c].second.second.second);
                        
                        s.insert(v[c].second.second.first);
                        
                        if (v[c].second.second.first > r) {
                            p++;
                        } else {
                            q++;
                        }
                    } else {
                        z[v[c].second.first].push_back(make_pair(v[c].second.second.first, v[c].second.second.second));
                        
                        s.insert(v[c].second.first);
                        
                        if (v[c].second.first > r) {
                            p++;
                        } else {
                            q++;
                        }
                    }
                    
                    c++;
                }                
            }
        }
    }
    
    for (i = 0; i < n; i++) printf("%I64d\n", ans[i]);
    
    return 0;
}