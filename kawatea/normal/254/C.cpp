#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    int n, p = 0, i, j;
    int a[26] = {0};
    int b[26] = {0};
    int c[26] = {0};
    int d[26] = {0};
    char s[100001];
    char t[100001];
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%s", s);
    fscanf(fp, "%s", t);
    
    fclose(fp);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        a[s[i] - 'A']++;
        b[t[i] - 'A']++;
    }
    
    for (i = 0; i < 26; i++) {
        if (a[i] > b[i]) {
            c[i] += a[i] - b[i];
            p += a[i] - b[i];
        } else if (a[i] < b[i]) {
            d[i] += b[i] - a[i];
            p += b[i] - a[i];
        }
    }
    
    p /= 2;
    
    for (i = 0; i < n; i++) {
        if (c[s[i] - 'A'] == 0) continue;
        
        for (j = 0; j < 26; j++) {
            if (d[j] > 0) break;
        }
        
        if (a[s[i] - 'A'] == c[s[i] - 'A'] || s[i] - 'A' > j) {
            a[s[i] - 'A']--;
            c[s[i] - 'A']--;
            d[j]--;
            s[i] = 'A' + j;
        } else {
            a[s[i] - 'A']--;
        }
    }
    
    fp = fopen("output.txt", "w");
    
    fprintf(fp, "%d\n", p);
    fprintf(fp, "%s\n", s);
    
    fclose(fp);
    
    return 0;
}