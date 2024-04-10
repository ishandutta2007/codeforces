#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int c[1000001];

int main()
{
    int a, b, k, i, j;
    vector <int> v;
    
    scanf("%d %d %d", &a, &b, &k);
    
    for (i = 2; i <= b; i++) {
        if (c[i] == 0) {
            if (i >= a) v.push_back(i);
            
            for (j = i * 2; j <= b; j += i) c[j] = 1;
        }
    }
    
    if (v.size() < k) {
        puts("-1");
    } else {
        int m = v[k - 1] - a + 1;
        
        for (i = 0; i + k < v.size(); i++) m = max(m, v[i + k] - v[i]);
        
        m = max(m, b - v[v.size() - k] + 1);
        
        printf("%d\n", m);
    }
    
    return 0;
}