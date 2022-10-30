#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char s[11];
char t[11];

int main()
{
    int n, m, i;
    map <string, string> mp;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf("%s %s", s, t);
        
        if (strlen(s) > strlen(t)) {
            mp[(string)s] = (string)t;
        } else {
            mp[(string)s] = (string)s;
        }
    }
    
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        
        if (i > 0) putchar(' ');
        
        printf("%s", mp[(string)s].c_str());
    }
    
    puts("");
    
    return 0;
}