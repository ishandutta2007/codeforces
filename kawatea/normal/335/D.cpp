#include <cstdio>
#include <vector>

using namespace std;

int a[100000][4];
int b[3005][3005];
int c[3005][3005];
int sum[3001][3001];

int get(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1];
}

int main()
{
    int n, i, j, k;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = a[i][0] + 1; j <= a[i][2]; j++) {
            for (k = a[i][1] + 1; k <= a[i][3]; k++) {
                sum[j][k]++;
            }
        }
    }
    
    for (i = 1; i <= 3000; i++) {
        for (j = 1; j <= 3000; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    
    for (i = 0; i < n; i++) {
        b[a[i][0]][a[i][1] + 1]++;
        b[a[i][0]][a[i][3] + 1]--;
        b[a[i][2]][a[i][1] + 1]++;
        b[a[i][2]][a[i][3] + 1]--;
        c[a[i][1]][a[i][0] + 1]++;
        c[a[i][1]][a[i][2] + 1]--;
        c[a[i][3]][a[i][0] + 1]++;
        c[a[i][3]][a[i][2] + 1]--;
    }
    
    for (i = 0; i <= 3000; i++) {
        for (j = 1; j < 3005; j++) {
            b[i][j] += b[i][j - 1];
            c[i][j] += c[i][j - 1];
        }
        
        for (j = 0; j < 3005; j++) {
            if (b[i][j] > 1) b[i][j] = 1;
            if (c[i][j] > 1) c[i][j] = 1;
        }
        
        for (j = 1; j < 3005; j++) {
            b[i][j] += b[i][j - 1];
            c[i][j] += c[i][j - 1];
        }
    }
    
    for (i = 0; i < n; i++) {
        int x1 = a[i][0];
        int y1 = a[i][1];
        
        for (j = 1; ; j++) {
            int x2, y2;
            
            x2 = a[i][0] + j;
            y2 = a[i][1] + j;
            
            if (x2 > 3000 || y2 > 3000) break;
            
            if (get(x1, y1, x2, y2) != j * j) break;
            
            if (b[x1][y2] - b[x1][y1] != j) break;
            if (c[y1][x2] - c[y1][x1] != j) break;
            
            if (b[x2][y2] - b[x2][y1] != j) continue;
            if (c[y2][x2] - c[y2][x1] != j) continue;
            
            for (k = 0; k < n; k++) {
                if (a[k][0] >= x1 && a[k][1] >= y1 && a[k][2] <= x2 && a[k][3] <= y2) v.push_back(k + 1);
            }
            
            printf("YES %d\n", v.size());
            
            for (k = 0; k < v.size(); k++) {
                if (k > 0) putchar(' ');
                
                printf("%d", v[k]);
            }
            
            puts("");
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}