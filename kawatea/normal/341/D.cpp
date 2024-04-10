#include <cstdio>
#include <algorithm>

using namespace std;

long long bit[2][2][1003][1003];

long long sum(int i, int j)
{
    int x = i & 1, y = j & 1, k = j;
    long long s = 0;
    
    while (i > 0) {
        while (j > 0) {
            s ^= bit[x][y][i][j];
            j -= j & -j;
        }
        
        i -= i & -i;
        j = k;
    }
    
    return s;
}

void add(int i, int j, long long v)
{
    int x = i & 1, y = j & 1, k = j;
    
    while (i <= 1002) {
        while (j <= 1002) {
            bit[x][y][i][j] ^= v;
            j += j & -j;
        }
        
        i += i & -i;
        j = k;
    }
}

int main()
{
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int t;
        
        scanf("%d", &t);
        
        if (t == 1) {
            int x1, y1, x2, y2;
            
            scanf("%d %d %d %d", &x1 ,&y1, &x2, &y2);
            
            x2++;
            y2++;
            
            printf("%I64d\n", sum(x1, y1) ^ sum(x1, y2) ^ sum(x2, y1) ^ sum(x2, y2));
        } else {
            int x1, y1, x2, y2;
            long long v;
            
            scanf("%d %d %d %d %I64d", &x1, &y1, &x2, &y2, &v);
            
            x1++;
            y1++;
            x2 += 2;
            y2 += 2;
            
            add(x1, y1, v);
            add(x1, y2, v);
            add(x2, y1, v);
            add(x2, y2, v);
        }
    }
    
    return 0;
}