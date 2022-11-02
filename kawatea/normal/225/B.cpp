#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int s, k, sum = 1, p = 2, i;
    vector <int> v, w;
    
    scanf("%d %d", &s, &k);
    
    v.push_back(0);
    v.push_back(1);
    
    for (i = 2; ; i++) {
        if (sum > s) break;
        
        v.push_back(sum);
        
        sum += sum;
        
        p++;
        
        if (p > k) {
            p--;
            
            sum -= v[i - p];
        }
    }
    
    while (s) {
        for (i = v.size() - 1; i >= 0; i--) {
            if (v[i] > s) continue;
            
            s -= v[i];
            
            w.push_back(v[i]);
            
            break;
        }
    }
    
    if (w.size() == 1) w.push_back(0);
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", w[i]);
    }
    
    puts("");
    
    return 0;
}