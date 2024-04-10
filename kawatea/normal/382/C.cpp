#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    vector <int> v, w;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i + 1 < v.size(); i++) w.push_back(v[i + 1] - v[i]);
    
    sort(w.begin(), w.end());
    
    if (w.size() == 0) {
        puts("-1");
    } else if (w[0] == w.back()) {
        if (w[0] == 0) {
            puts("1");
            printf("%d\n", v[0]);
        } else if (w.size() == 1 && w[0] % 2 == 0) {
            puts("3");
            printf("%d %d %d\n", v[0] - w[0], v[0] + w[0] / 2, v.back() + w[0]);
        } else {
            puts("2");
            printf("%d %d\n", v[0] - w[0], v.back() + w[0]);
        }
    } else if (w[0] == w[w.size() - 2] && w[0] * 2 == w.back()) {
        for (i = 0; i + 1 < v.size(); i++) {
            if (v[i + 1] - v[i] == w.back()) break;
        }
        
        puts("1");
        printf("%d\n", v[i] + w[0]);
    } else {
        puts("0");
    }
    
    return 0;
}