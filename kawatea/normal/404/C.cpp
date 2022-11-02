#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[100000];

int main()
{
    int n, i;
    long long k, j, l;
    vector <pair<int, int> > w;
    
    scanf("%d %I64d", &n, &k);
    
    for (i = 0; i < n; i++) {
        int x;
        
        scanf("%d", &x);
        
        v[x].push_back(i + 1);
    }
    
    if (v[0].size() != 1) {
        puts("-1");
        
        return 0;
    }
    
    n--;
    
    for (i = 1; n > 0; i++) {
        if (v[i].size() == 0) {
            puts("-1");
            
            return 0;
        }
        
        if (i == 1) {
            if (v[i - 1].size() * k < v[i].size()) {
                puts("-1");
                
                return 0;
            }
            
            for (j = 0; j < v[i - 1].size(); j++) {
                for (l = j * k; l < (j + 1) * k && l < v[i].size(); l++) {
                    w.push_back(make_pair(v[i - 1][j], v[i][l]));
                }
            }
        } else {
            if (v[i - 1].size() * (k - 1) < v[i].size()) {
                puts("-1");
                
                return 0;
            }
            
            for (j = 0; j < v[i - 1].size(); j++) {
                for (l = j * (k - 1); l < (j + 1) * (k - 1) && l < v[i].size(); l++) {
                    w.push_back(make_pair(v[i - 1][j], v[i][l]));
                }
            }
        }
        
        n -= v[i].size();
    }
    
    printf("%d\n", w.size());
    
    for (i = 0; i < w.size(); i++) printf("%d %d\n", w[i].first, w[i].second);
    
    return 0;
}