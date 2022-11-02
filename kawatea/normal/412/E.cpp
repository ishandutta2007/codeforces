#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char s[1000001];

int main()
{
    int n, i, j;
    long long ans = 0;
    vector <int> v;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) {
        if (s[i] == '@') v.push_back(i);
    }
    
    for (i = 0; i < v.size(); i++) {
        int f = 0;
        long long c1 = 0, c2 = 0;
        
        for (j = v[i] - 1; j >= 0; j--) {
            if (s[j] == '.' || s[j] == '@') break;
            
            if (s[j] >= 'a' && s[j] <= 'z') c1++;
        }
        
        for (j = v[i] + 1; j < n; j++) {
            if (s[j] == '@' || s[j] == '_') break;
            
            if (s[j] == '.') {
                if (f == 1 || j == v[i] + 1) break;
                
                f++;
            } else if (s[j] >= '0' && s[j] <= '9') {
                if (f == 1) break;
            } else {
                if (f == 1) c2++;
            }
        }
        
        ans += c1 * c2;
    }
    
    printf("%I64d\n", ans);
    
    return 0;
}