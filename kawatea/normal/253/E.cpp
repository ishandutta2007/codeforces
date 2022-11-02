#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, c, l, r, m, i;
    long long t;
    long long a[50000];
    vector <pair<int, pair<int, pair<int, int> > > > v;
    vector <int> w;
    set <int> s;
    set <int>::iterator it;
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y, z;
        
        fscanf(fp, "%d %d %d", &x, &y, &z);
        
        v.push_back(make_pair(x, make_pair(y, make_pair(z, i))));
        
        if (z != -1) {
            s.insert(z);
        } else {
            c = i;
        }
    }
    
    fscanf(fp, "%I64d", &t);
    
    fclose(fp);
    
    s.insert(0);
    s.insert(1e9 + 1);
    
    for (it = s.begin(); it != s.end(); it++) {
        set <int>::iterator it2 = it;
        
        it2++;
        
        if (it2 == s.end()) break;
        
        if (*it2 - *it > 1) w.push_back(*it + 1);
    }
    
    sort(v.begin(), v.end());

    l = -1, r = w.size(), m = (l + r) / 2;
    
    while (r - l > 1) {
        int p = 1;
        long long d = v[0].first;
        priority_queue <pair<int, pair<int, int> > > q;
        
        if (v[0].second.second.first == -1) {
            q.push(make_pair(w[m], make_pair(v[0].second.first, v[0].second.second.second)));
        } else {
            q.push(make_pair(v[0].second.second.first, make_pair(v[0].second.first, v[0].second.second.second)));
        }
        
        while (1) {
            int x, y, z;
            
            if (q.empty()) {
                if (p == v.size()) break;
                
                d = v[p].first;
                
                if (v[p].second.second.first == -1) {
                    q.push(make_pair(w[m], make_pair(v[p].second.first, v[p].second.second.second)));
                } else {
                    q.push(make_pair(v[p].second.second.first, make_pair(v[p].second.first, v[p].second.second.second)));
                }
                
                p++;
                
                continue;
            }
            
            x = q.top().first;
            y = q.top().second.first;
            z = q.top().second.second;
            
            q.pop();
            
            if (p == v.size() || d + y <= v[p].first) {
                d += y;
                
                a[z] = d;
            } else {
                y -= v[p].first - d;
                
                d = v[p].first;
                
                if (v[p].second.second.first == -1) {
                    q.push(make_pair(w[m], make_pair(v[p].second.first, v[p].second.second.second)));
                } else {
                    q.push(make_pair(v[p].second.second.first, make_pair(v[p].second.first, v[p].second.second.second)));
                }
                
                q.push(make_pair(x, make_pair(y, z)));
                
                p++;
            }
        }
        
        if (a[c] == t) {
            fp = fopen("output.txt", "w");
            
            fprintf(fp, "%d\n", w[m]);
            
            for (i = 0; i < n; i++) {
                if (i > 0) fprintf(fp, " ");
                
                fprintf(fp, "%I64d", a[i]);
            }
            
            fclose(fp);
            
            return 0;
        }
        
        if (a[c] > t) {
            l = m;
            m = (l + r) / 2;
        } else {
            r = m;
            m = (l + r) / 2;
        }
    }
    
    return 0;
}