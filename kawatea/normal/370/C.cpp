#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, c = 0, i, j;
    int a[100] = {0};
    int b[5000][2];
    vector <pair<int, int> > v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        a[x - 1]++;
    }
    
    for (i = 0; i < m; i++) {
        if (a[i] > 0) v.push_back(make_pair(a[i] * 2, i));
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (i = 0, j = 0; i < n; i++) {
        b[i][i % 2] = v[j].second + 1;
        v[j].first--;
        
        if (v[j].first == 0) j++;
    }
    
    for (i = 0; i < n; i++) {
        b[i][(i + 1) % 2] = v[j].second + 1;
        v[j].first--;
        
        if (v[j].first == 0) j++;
        
        if (b[i][0] != b[i][1]) c++;
    }
    
    printf("%d\n", c);
    
    for (i = 0; i < n; i++) printf("%d %d\n", b[i][0], b[i][1]);
    
    return 0;
}