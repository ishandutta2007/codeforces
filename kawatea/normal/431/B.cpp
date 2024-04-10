#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[5][5];

int main()
{
    int ans = 0, i, j;
    vector <int> v;
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 0; i < 5; i++) v.push_back(i);
    
    do {
        int sum = 0;
        
        for (i = 0; i < 5; i++) {
            for (j = i; j < 5; j += 2) {
                if (j + 1 < 5) sum += a[v[j]][v[j + 1]] + a[v[j + 1]][v[j]];
            }
        }
        
        ans = max(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    
    printf("%d\n", ans);
    
    return 0;
}