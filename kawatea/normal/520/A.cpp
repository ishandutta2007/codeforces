#include <cstdio>

using namespace std;

int a[26];
char s[101];

int main()
{
    int n, i;
    
    scanf("%d", &n);
    scanf("%s", s);
    
    for (i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            a[s[i] - 'A']++;
        } else {
            a[s[i] - 'a']++;
        }
    }
    
    for (i = 0; i < 26; i++) {
        if (a[i] == 0) {
            puts("NO");
            
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}