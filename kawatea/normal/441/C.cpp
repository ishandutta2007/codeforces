#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, m, k, c, i, j;
    vector <pair<int, int> > v;
    
    scanf("%d %d %d", &n, &m, &k);
    
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < m; j++) v.push_back(make_pair(i + 1, j + 1));
        } else {
            for (j = m - 1; j >= 0; j--) v.push_back(make_pair(i + 1, j + 1));
        }
    }
    
    c = n * m - 2 * (k - 1);
    
    printf("%d", c);
    
    for (i = 0; i < c; i++) printf(" %d %d", v[i].first, v[i].second);
    
    puts("");
    
    for (i = 0; i < k - 1; i++) {
        printf("%d %d %d %d %d\n", 2, v[c + i * 2].first, v[c + i * 2].second, v[c + i * 2 + 1].first, v[c + i * 2 + 1].second);
    }
    
    return 0;
}