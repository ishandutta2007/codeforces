#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char s[1000001];

int main()
{
    int n, x = 0, f = 0, i, j;
    int a[10] = {0};
    vector <int> v;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) a[s[i] - '0']++;
    
    a[1]--;
    a[6]--;
    a[8]--;
    a[9]--;
    
    for (i = 9, j = 0; i > 0; i--) {
        while (a[i]) {
            x = x * 10 + i;
            x %= 7;
            
            a[i]--;
            
            s[j++] = i + '0';
        }
    }
    
    v.push_back(1);
    v.push_back(6);
    v.push_back(8);
    v.push_back(9);
    
    do {
        int y = x;
        
        for (i = 0; i < 4; i++) {
            y *= 10;
            y += v[i];
        }
        
        if (y % 7 == 0) {
            f = 1;
            
            break;
        }
    } while (next_permutation(v.begin(), v.end()));
    
    if (f == 0) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < 4; i++) s[j++] = v[i] + '0';
    
    for (; j < n; j++) s[j] = '0';
    
    printf("%s\n", s);
    
    return 0;
}