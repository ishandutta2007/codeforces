#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
int a[100000], p[100000];
int main() {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < n; i++)
        scanf("%d", p + i);
    transform(p, p + n, a, a, plus<int>());
    int maxi = *max_element(a, a + n);
    if(maxi > r) {
        using std::placeholders::_1;
        transform(a, a + n, a, bind(minus<int>(), _1, maxi - r));
        if(*min_element(a, a + n) < l) {
            puts("-1");
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}