#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, c = 0, sum = 0, i;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (i = 0; i < 2 * n - 1; i++) {
        int x;
        
        scanf("%d", &x);
        
        if (x < 0) {
            x = -x;
            c++;
        }
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    if (n % 2 == 0) {
        c %= 2;
    } else {
        c = 0;
    }
    
    for (i = 0; i < c; i++) sum -= v[i];
    for (; i < v.size(); i++) sum += v[i];
    
    printf("%d\n", sum);
    
    return 0;
}