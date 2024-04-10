#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100001];
int b[100001];

int main()
{
    int n, i, j;
    vector <pair<int, int> > v;
    
    scanf("%d", &n);
    
    a[0] = a[1] = 1;
    
    for (i = 2; i <= 100000; i++) {
        if (a[i] == 0) {
            for (j = i * 2; j <= 100000; j += i) a[j] = 1;
        }
    }
    
    for (i = n; i > 0; i--) {
        if (a[i] == 0) {
            vector <int> w;
            
            for (j = i; j <= n; j += i) {
                if (b[j] == 0) w.push_back(j);
            }
            
            if (w.size() % 2 == 0) {
                for (j = 0; j < w.size(); j += 2) {
                    v.push_back(make_pair(w[j], w[j + 1]));
                    
                    b[w[j]] = b[w[j + 1]] = 1;
                }
            } else {
                for (j = 0; j < w.size(); j++) {
                    if (w[j] % 2 == 0) {
                        swap(w[j], w.back());
                        
                        break;
                    }
                }
                
                for (j = 0; j < w.size() - 1; j += 2) {
                    v.push_back(make_pair(w[j], w[j + 1]));
                    
                    b[w[j]] = b[w[j + 1]] = 1;
                }
            }
        }
    }
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}