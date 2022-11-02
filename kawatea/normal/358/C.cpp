#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char s1[3][10] = {"popQueue", "popStack", "popFront"};

int main()
{
    int n, i, j, k;
    int a[100000];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int c = 0;
        vector <pair<int, int> > v;
        set <int> s;
        
        for (j = i; j < n; j++) {
            if (a[j] == 0) break;
            
            v.push_back(make_pair(a[j], j));
        }
        
        if (j == n) {
            for (j = i; j < n; j++) puts("pushStack");
            
            return 0;
        }
        
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        
        for (k = 0; k < 3 && k < v.size(); k++) s.insert(v[k].second);
        
        for (k = i; k < j; k++) {
            if (s.count(k)) {
                if (c == 0) {
                    puts("pushQueue");
                } else if (c == 1) {
                    puts("pushStack");
                } else {
                    puts("pushFront");
                }
                
                c++;
            } else {
                if (c == 0) {
                    puts("pushStack");
                } else {
                    puts("pushQueue");
                }
            }
        }
        
        printf("%d", c);
        
        for (k = 0; k < c; k++) printf(" %s", s1[k]);
        
        puts("");
        
        i = j;
    }
    
    return 0;
}