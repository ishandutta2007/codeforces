#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[100000];
int fnd[100000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    fill_n(fnd, n, -1);
    for(int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        for(int j = 0; j < x; j++) {
            int y;
            scanf("%d", &y);
            v[i].push_back(y - 1);
        }
        fnd[v[i][0]] = i;
    }
    int ans = (n - k) + (n - 1);
    int x = 0;
    for(int i : v[fnd[x]])
        if(i == x++)
            ans -= 2;
        else
            break;
    ans += 2;
    printf("%d\n", ans);
}