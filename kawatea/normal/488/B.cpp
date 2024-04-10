#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, j;
    vector <int> v;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v.push_back(x);
    }
    
    for (i = 1; i * 3 <= 1000000; i++) {
        int f1 = 0, f2 = 0;
        vector <int> w;
        
        w.push_back(i);
        w.push_back(i * 3);
        
        for (j = 0; j < v.size(); j++) {
            if (v[j] == i) {
                if (f1 == 1) w.push_back(v[j]);
                f1 = 1;
            } else if (v[j] == i * 3) {
                if (f2 == 1) w.push_back(v[j]);
                f2 = 1;
            } else {
                w.push_back(v[j]);
            }
        }
        
        if (w.size() > 4) continue;
        
        if (w.size() == 2) {
            w.push_back(i * 2);
            w.push_back(i * 2);
        } else if (w.size() == 3) {
            w.push_back(i * 4 - w.back());
        }
        
        sort(w.begin(), w.end());
        
        for (j = 0; j < 4; j++) {
            if (w[j] <= 0 || w[j] > 1000000) break;
        }
        
        if (j < 4) continue;
        
        if ((w[3] - w[0]) * 2 == w[1] + w[2] && w[0] + w[3] == w[1] + w[2]) {
            puts("YES");
            
            for (i = 0; i < w.size(); i++) {
                for (j = 0; j < v.size(); j++) {
                    if (w[i] == v[j]) {
                        v[j] = -1;
                        
                        break;
                    }
                }
                
                if (j == v.size()) printf("%d\n", w[i]);
            }
            
            return 0;
        }
    }
    
    puts("NO");
    
    return 0;
}