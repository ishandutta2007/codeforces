#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j;
    vector <int> v;
    vector <int> w1, w2;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for (i = 0; i < v.size(); ) {
        for (j = i; j < v.size(); j++) {
            if (v[i] != v[j]) break;
        }
        
        w1.push_back(v[i]);
        if (j > i + 1) w2.push_back(v[i]);
        
        i = j;
    }
    
    if (w2.size() > 0 && w1.back() == w2.back()) w2.pop_back();
    
    reverse(w2.begin(), w2.end());
    
    printf("%d\n", w1.size() + w2.size());
    
    for (i = 0; i < w1.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w1[i]);
    }
    
    for (i = 0; i < w2.size(); i++) {
        printf(" %d", w2[i]);
    }
    
    puts("");
    
    return 0;
}