#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char c[5] = "RULD";

int main()
{
    int n, i;
    int a[100000][2];
    vector <pair<int, int> > v;
    vector <pair<int, pair<int, int> > > w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        
        v.push_back(make_pair(abs(a[i][0]) + abs(a[i][1]), i));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        int x = v[i].second;
        
        if (a[x][0] > 0) w.push_back(make_pair(1, make_pair(a[x][0], 0)));
        if (a[x][1] > 0) w.push_back(make_pair(1, make_pair(a[x][1], 1)));
        if (a[x][0] < 0) w.push_back(make_pair(1, make_pair(-a[x][0], 2)));
        if (a[x][1] < 0) w.push_back(make_pair(1, make_pair(-a[x][1], 3)));
        
        w.push_back(make_pair(2, make_pair(0, 0)));
        
        if (a[x][0] > 0) w.push_back(make_pair(1, make_pair(a[x][0], 2)));
        if (a[x][1] > 0) w.push_back(make_pair(1, make_pair(a[x][1], 3)));
        if (a[x][0] < 0) w.push_back(make_pair(1, make_pair(-a[x][0], 0)));
        if (a[x][1] < 0) w.push_back(make_pair(1, make_pair(-a[x][1], 1)));
        
        w.push_back(make_pair(3, make_pair(0, 0)));
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) {
        if (w[i].first == 1) {
            printf("%d %d %c\n", w[i].first, w[i].second.first, c[w[i].second.second]);
        } else {
            printf("%d\n", w[i].first);
        }
    }
    
    return 0;
}