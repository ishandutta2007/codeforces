#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int j, k, l;
        char s[13];
        vector <int> v;
        
        scanf("%s", s);
        
        for (j = 1; j <= 12; j++) {
            if (12 % j != 0) continue;
            
            for (k = 0; k < 12 / j; k++) {
                for (l = k; l < 12; l += 12 / j) {
                    if (s[l] == 'O') break;
                }
                
                if (l >= 12) {
                    v.push_back(j);
                    
                    break;
                }
            }
        }
        
        printf("%d", v.size());
        
        for (j = 0; j < v.size(); j++) printf(" %dx%d", v[j], 12 / v[j]);
        
        puts("");
    }
    
    return 0;
}