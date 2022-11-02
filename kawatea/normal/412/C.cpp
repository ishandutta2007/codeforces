#include <cstdio>
#include <vector>
#include <string>

using namespace std;

char s[100001];

int main()
{
    int n, i, j;
    vector <string> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%s", s);
        
        v.push_back((string)s);
    }
    
    for (i = 0; i < v[0].size(); i++) {
        int x = -1;
        
        for (j = 0; j < n; j++) {
            if (v[j][i] == '?') continue;
            
            if (x == -1) {
                x = v[j][i] - 'a';
            } else if (x != v[j][i] - 'a') {
                x = -2;
            }
        }
        
        if (x == -1) {
            putchar('a');
        } else if (x == -2) {
            putchar('?');
        } else {
            putchar(x + 'a');
        }
    }
    
    puts("");
    
    return 0;
}