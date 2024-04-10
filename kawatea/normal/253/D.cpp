#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int n, m, k, i, j, l;
    long long sum = 0;
    int a[401][401] = {0};
    char s[400][401];
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) fscanf(fp, "%s", s[i]);
    
    fclose(fp);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 'a') a[i + 1][j + 1]++;
            
            a[i + 1][j + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            vector <int> v[26];
            
            for (l = 0; l < m; l++) {
                if (s[i][l] == s[j][l]) v[s[i][l] - 'a'].push_back(l);
            }
            
            for (l = 0; l < 26; l++) {
                int p = 0, q = 0;
                
                if (v[l].size() == 0) continue;
                
                for (; p < v[l].size(); p++) {
                    while (p > q) {
                        if (a[j + 1][v[l][p] + 1] - a[j + 1][v[l][q]] - a[i][v[l][p] + 1] + a[i][v[l][q]] <= k) break;
                        
                        q++;
                    }
                    
                    sum += p - q;
                }
            }
        }
    }
    
    fp = fopen("output.txt", "w");
    
    fprintf(fp, "%I64d\n", sum);
    
    fclose(fp);
    
    return 0;
}