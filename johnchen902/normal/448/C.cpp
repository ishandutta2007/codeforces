#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int a[5000];

int solve(int l, int r) {
    if(l == r)
        return 0;
    int vert = (r - l);
    int mini = *min_element(a + l, a + r);
    transform(a + l, a + r, a + l, bind(minus<int>(), _1, mini));
    long long hori = mini;
    while(l != r) {
        int *p1 = find_if(a + l, a + r, bind(not_equal_to<int>(), _1, 0));
        if(p1 == a + r) break;
        int *p2 = find(p1, a + r, 0);
        hori += solve(p1 - a, p2 - a);
        l = p2 - a;
    }
    return min((long long) vert, hori);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("%d\n", solve(0, n));
}