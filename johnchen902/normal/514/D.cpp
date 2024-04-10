#include <cstdio>
#include <set>
using namespace std;
multiset<int> det[5];

int get_max(int type) {
    if(det[type].empty())
        return 0;
    return *--det[type].end();
}

int a[100000][5];
int use[5];
int best_len;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", a[i] + j);
    for(int l = 0, r = 0; r <= n;) {
        int need = 0;
        for(int i = 0; i < m; i++)
            need += get_max(i);
        if(need <= k) {
            if(r - l > best_len) {
                for(int i = 0; i < m; i++)
                    use[i] = get_max(i);
                best_len = r - l;
            }
            if(r < n) {
                for(int i = 0; i < m; i++)
                    det[i].insert(a[r][i]);
            }
            r++;
        } else {
            if(l < n) {
                for(int i = 0; i < m; i++)
                    det[i].erase(det[i].find(a[l][i]));
            }
            l++;
        }
    }
    for(int i = 0; i < m; i++)
        printf("%d ", use[i]);
}