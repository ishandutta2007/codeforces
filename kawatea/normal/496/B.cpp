#include <cstdio>

using namespace std;

char s[1001];
char t[1001];
char ans[1001];

int main()
{
    int n, i, j;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) ans[i] = '9';
    
    for (i = 0; i < n; i++) {
        int x = s[i] - '0';
        
        for (j = i; j < n; j++) {
            t[j - i] = s[j] - x;
            if (t[j - i] < '0') t[j - i] += 10;
        }
        
        for (j = 0; j < i; j++) {
            t[n - i + j] = s[j] - x;
            if (t[n - i + j] < '0') t[n - i + j] += 10;
        }
        
        for (j = 0; j < n; j++) {
            if (t[j] > ans[j]) break;
            
            if (t[j] < ans[j]) {
                for (j = 0; j < n; j++) ans[j] = t[j];
                
                break;
            }
        }
    }
    
    printf("%s\n", ans);
    
    return 0;
}