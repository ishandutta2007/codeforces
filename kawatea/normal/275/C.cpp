#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, sum = 0, i;
    vector <long long> v;
    set <long long> s;
    
    scanf("%d %d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); i++) {
        if (s.count(v[i])) continue;
        
        sum++;
        
        s.insert(v[i] * k);
    }
    
    printf("%d\n", sum);
    
    return 0;
}