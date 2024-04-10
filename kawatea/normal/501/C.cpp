#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int a[100000][2];

int main()
{
    int n, i;
    vector <pair<int, int> > v;
    queue <int> q;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    
    for (i = 0; i < n; i++) {
        if (a[i][0] == 1) q.push(i);
    }
    
    while (!q.empty()) {
        int x = q.front();
        int y = a[x][1];
        
        q.pop();
        
        if (a[x][0] == 1) {
            a[x][0]--;
            a[y][0]--;
            a[y][1] ^= x;
            
            v.push_back(make_pair(x, y));
        }
        
        if (a[y][0] == 1) q.push(y);
    }
    
    printf("%d\n", (int)v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}