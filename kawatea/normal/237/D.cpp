#include <cstdio>
#include <vector>

using namespace std;

vector <int> e[100000];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    
    printf("%d\n", n - 1);
    
    for (i = 0; i < n - 1; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        printf("2 %d %d\n", x, y);
        
        e[x - 1].push_back(i + 1);
        e[y - 1].push_back(i + 1);
    }
    
    for (i = 0; i < n; i++) {
        if (e[i].size() > 1) {
            for (j = 0; j < e[i].size() - 1; j++) printf("%d %d\n", e[i][j], e[i][j + 1]);
        }
    }
    
    return 0;
}