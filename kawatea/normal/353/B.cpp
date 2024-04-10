#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c = 0, ans = 0, i, j;
    int a[200];
    int b[100][2] = {0};
    vector <int> v[100];
    vector <pair<int, int> > w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n * 2; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[x].push_back(i);
    }
    
    for (i = 0; i < 100; i++) {
        if (v[i].size() > 0) w.push_back(make_pair(v[i].size(), i));
    }
    
    sort(w.begin(), w.end());
    
    for (i = 0; i < w.size(); i++) {
        for (j = 0; j < w[i].first; j++) {
            if (c % 2 == 0) {
                a[v[w[i].second][j]] = 1;
                
                b[w[i].second][0] = 1;
            } else {
                a[v[w[i].second][j]] = 2;
                
                b[w[i].second][1] = 1;
            }
            
            c++;
        }
    }
    
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (b[i][0] == 1 && b[j][1] == 1) ans++;
        }
    }
    
    printf("%d\n", ans);
    
    for (i = 0; i < n * 2; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", a[i]);
    }
    
    puts("");
    
    return 0;
}