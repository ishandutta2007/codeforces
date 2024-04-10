#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[300][301];

int gcd(int a, int b)
{
    if (b == 0) return a;
    
    return gcd(b, a % b);
}

double area(int x, int y, int z, pair<int, int> s, pair<int, int> t)
{
    double x1 = (double)s.second / s.first;
    double x2 = (double)t.second / t.first;
    double y1 = a[x][z] + (a[x][z + 1] - a[x][z]) * x1;
    double y2 = a[x][z] + (a[x][z + 1] - a[x][z]) * x2;
    double y3 = a[y][z] + (a[y][z + 1] - a[y][z]) * x1;
    double y4 = a[y][z] + (a[y][z + 1] - a[y][z]) * x2;
    
    return (y1 + y2 - y3 - y4) / 2 * (x2 - x1);
}

int main()
{
    int n, k, i, j, l;
    double ans[300] = {0};
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j <= k; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < k; i++) {
        vector <int> v;
        vector <pair<int, int> > w;
        
        ans[0] += (a[0][i] + a[0][i + 1]) / 2.0;
        
        v.push_back(0);
        w.push_back(make_pair(1, 0));
        w.push_back(make_pair(1, 1));
        
        for (j = 1; j < n; j++) {
            vector <pair<int, int> > z;
            
            for (l = 0; l < v.size(); l++) {
                int y1 = a[j][i + 1] - a[j][i] - a[v[l]][i + 1] + a[v[l]][i];
                int y2 = a[v[l]][i] - a[j][i];
                int g;
                
                if (y1 * y2 <= 0) continue;
                
                y1 = abs(y1);
                y2 = abs(y2);
                
                g = gcd(y1, y2);
                
                y1 /= g;
                y2 /= g;
                
                if (w[l].first * y2 < w[l].second * y1) continue;
                if (w[l + 1].first * y2 >= w[l + 1].second * y1) continue;
                
                z.push_back(make_pair(y1, y2));
            }
            
            if (z.size() == 0) {
                if (a[j][i] > a[v[0]][i] || (a[j][i] == a[v[0]][i] && a[j][i + 1] > a[v[0]][i + 1])) {
                    for (l = 0; l < v.size(); l++) ans[j] += area(j, v[l], i, w[l], w[l + 1]);
                    
                    v.clear();
                    v.push_back(j);
                    
                    w.clear();
                    w.push_back(make_pair(1, 0));
                    w.push_back(make_pair(1, 1));
                }
            } else if (z.size() == 1) {
                vector <int> v2;
                vector <pair<int, int> > w2;
                
                if (a[j][i] >= a[v[0]][i]) {
                    v2.push_back(j);
                    w2.push_back(make_pair(1, 0));
                    
                    for (l = 0; l < v.size(); l++) {
                        if (w[l + 1].first * z[0].second < w[l + 1].second * z[0].first) {
                            ans[j] += area(j, v[l], i, w[l], z[0]);
                            
                            v2.push_back(v[l]);
                            w2.push_back(z[0]);
                            
                            break;
                        } else {
                            ans[j] += area(j, v[l], i, w[l], w[l + 1]);
                        }
                    }
                    
                    for (l++; l < v.size(); l++) {
                        v2.push_back(v[l]);
                        w2.push_back(w[l]);
                    }
                    
                    w2.push_back(make_pair(1, 1));
                } else if (a[j][i + 1] >= a[v.back()][i + 1]) {
                    for (l = 0; l < v.size(); l++) {
                        if (w[l + 1].first * z[0].second < w[l + 1].second * z[0].first) {
                            ans[j] += area(j, v[l], i, z[0], w[l + 1]);
                            
                            if (w[l] != z[0]) {
                                v2.push_back(v[l]);
                                w2.push_back(w[l]);
                            }
                            
                            v2.push_back(j);
                            w2.push_back(z[0]);
                            
                            break;
                        }
                        
                        v2.push_back(v[l]);
                        w2.push_back(w[l]);
                    }
                    
                    for (l++; l < v.size(); l++) ans[j] += area(j, v[l], i, w[l], w[l + 1]);
                    
                    w2.push_back(make_pair(1, 1));
                } else {
                    continue;
                }
                
                v = v2;
                w = w2;
            } else {
                vector <int> v2;
                vector <pair<int, int> > w2;
                
                for (l = 0; l < v.size(); l++) {
                    if (w[l + 1].first * z[0].second < w[l + 1].second * z[0].first) {
                        ans[j] += area(j, v[l], i, z[0], w[l + 1]);
                        
                        if (w[l] != z[0]) {
                            v2.push_back(v[l]);
                            w2.push_back(w[l]);
                        }
                        
                        v2.push_back(j);
                        w2.push_back(z[0]);
                        
                        break;
                    }
                    
                    v2.push_back(v[l]);
                    w2.push_back(w[l]);
                }
                
                for (l++; l < v.size(); l++) {
                    if (w[l + 1].first * z[1].second < w[l + 1].second * z[1].first) {
                        ans[j] += area(j, v[l], i, w[l], z[1]);
                        
                        v2.push_back(v[l]);
                        w2.push_back(z[1]);
                        
                        break;
                    } else {
                        ans[j] += area(j, v[l], i, w[l], w[l + 1]);
                    }
                }
                
                for (l++; l < v.size(); l++) {
                    v2.push_back(v[l]);
                    w2.push_back(w[l]);
                }
                
                w2.push_back(make_pair(1, 1));
                
                v = v2;
                w = w2;
            }
        }
    }
    
    for (i = 0; i < n; i++) printf("%.12lf\n", ans[i]);
    
    return 0;
}