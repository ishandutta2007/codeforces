#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int h, t;
vector <int> v[100000];

void put(int x, int y)
{
    int i, j;
    vector <int> w[3];
    
    puts("YES");
    printf("%d %d\n", x + 1, y + 1);
    
    for (i = 0, j = 0; ; ) {
        if (i == v[x].size() && j == v[y].size()) break;
        
        if (i == v[x].size()) {
            if (v[y][j] != x) w[2].push_back(v[y][j]);
            j++;
        } else if (j == v[y].size()) {
            if (v[x][i] != y) w[0].push_back(v[x][i]);
            i++;
        } else if (v[x][i] < v[y][j]) {
            if (v[x][i] != y) w[0].push_back(v[x][i]);
            i++;
        } else if (v[x][i] == v[y][j]) {
            w[1].push_back(v[x][i]);
            i++;
            j++;
        } else {
            if (v[y][j] != x) w[2].push_back(v[y][j]);
            j++;
        }
    }
    
    while (w[0].size() < h) {
        w[0].push_back(w[1].back());
        w[1].pop_back();
    }
    
    while (w[2].size() < t) {
        w[2].push_back(w[1].back());
        w[1].pop_back();
    }
    
    for (i = 0; i < h; i++) {
        if (i > 0) putchar(' ');
        printf("%d", w[0][i] + 1);
    }
    puts("");
    
    for (i = 0; i < t; i++) {
        if (i > 0) putchar(' ');
        printf("%d", w[2][i] + 1);
    }
    puts("");
}

int main()
{
    int n, m, i, j;
    
    scanf("%d %d %d %d", &n, &m, &h, &t);
    
    for (i = 0; i < m; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < v[i].size(); j++) {
            int x = i, y = v[i][j];
            
            if (max(v[x].size(), v[y].size()) >= h + t + 1) {
                if (v[x].size() >= h + 1 && v[y].size() >= t + 1) {
                    put(x, y);
                    
                    return 0;
                } else if (v[x].size() >= t + 1 && v[y].size() >= h + 1) {
                    put(y, x);
                    
                    return 0;
                }
            } else {
                vector <int> w;
                
                set_intersection(v[x].begin(), v[x].end(), v[y].begin(), v[y].end(), back_inserter(w));
                
                if (v[x].size() >= h + 1 && v[y].size() >= t + 1 && v[x].size() + v[y].size() - w.size() >= h + t + 2) {
                    put(x, y);
                    
                    return 0;
                } else if (v[x].size() >= h + 1 && v[y].size() >= t + 1 && v[x].size() + v[y].size() - w.size() >= h + t + 2) {
                    put(y, x);
                    
                    return 0;
                }
            }
        }
    }
    
    puts("NO");
    
    return 0;
}