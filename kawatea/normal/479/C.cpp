#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x = 0, i;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        scanf("%d %d", &x, &y);
        
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (v[i].second >= x) {
            x = v[i].second;
        } else {
            x = v[i].first;
        }
    }
    
    printf("%d\n", x);
    
    return 0;
}