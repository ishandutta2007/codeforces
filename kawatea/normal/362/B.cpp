#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, i;
    vector <int> v;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    if (v.size() == 0) {
        puts("YES");
        
        return 0;
    }
    
    if (v[0] == 1 || v.back() == n) {
        puts("NO");
        
        return 0;
    }
    
    for (i = 0; i + 2 < v.size(); i++) {
        if (v[i] + 2 == v[i + 2]) {
            puts("NO");
            
            return 0;
        }
    }
    
    puts("YES");
    
    return 0;
}