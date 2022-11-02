#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000][2];

int main()
{
    int n, i;
    vector <pair<int, int> > v;
    vector <int> w1, w2;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = 0; i < n; i++) {
        b[i][0] = w1.size();
        b[i][1] = w2.size();
        
        if (a[i] == 1) {
            w1.push_back(i);
        } else {
            w2.push_back(i);
        }
    }
    
    for (i = 1; i <= n; i++) {
        int p = 0, c1 = 0, c2 = 0, last = 0;
        
        while (p < n) {
            int x = b[p][0];
            int y = b[p][1];
            
            if (x + i > w1.size() && y + i > w2.size()) {
                break;
            } else if (x + i <= w1.size() && y + i <= w2.size()) {
                if (w1[x + i - 1] < w2[y + i - 1]) {
                    c1++;
                    last = 1;
                    p = w1[x + i - 1] + 1;
                } else {
                    c2++;
                    last = 2;
                    p = w2[y + i - 1] + 1;
                }
            } else if (x + i <= w1.size()) {
                c1++;
                last = 1;
                p = w1[x + i - 1] + 1;
            } else {
                c2++;
                last = 2;
                p = w2[y + i - 1] + 1;
            }
        }
        
        if (p == n) {
            if ((last == 1 && c1 > c2) || (last == 2 && c1 < c2)) {
                v.push_back(make_pair(max(c1, c2), i));
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    printf("%d\n", v.size());
    
    for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
    
    return 0;
}