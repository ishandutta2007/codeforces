#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, i;
    vector <int> v;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    printf("%d\n", v[n - k]);
    
    return 0;
}