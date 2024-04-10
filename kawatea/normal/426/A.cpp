#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, s, i;
    vector <int> v;
    
    scanf("%d %d", &n, &s);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < n - 1; i++) s -= v[i];
    
    if (s >= 0) {
        puts("YES");
    } else {
        puts("NO");
    }
    
    return 0;
}