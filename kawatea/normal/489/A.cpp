#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[3000];

int main()
{
    int n, i, j;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        int x = i;
        
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[x]) x = j;
        }
        
        if (x != i) {
            v.push_back(make_pair(i, x));
            
            swap(a[i], a[x]);
        }
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}