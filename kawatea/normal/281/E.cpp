#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[100000];

double dfs(int x, int y, int z)
{
    int i;
    double ans = 1.0 / z;
    
    for (i = 0; i < v[x].size(); i++) {
        if (v[x][i] == y) continue;
        
        ans += dfs(v[x][i], x, z + 1);
    }
    
    return ans;
}

int main()
{
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        x--;
        y--;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    printf("%.12lf\n", dfs(0, -1, 1));
    
    return 0;
}