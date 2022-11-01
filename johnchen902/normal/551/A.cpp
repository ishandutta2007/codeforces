#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int a[2000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < n; i++)
        printf("%d%c", 1 + (int) count_if(a, a + n, bind(greater<int>(), _1, a[i])),
                       i == n - 1 ? '\n' : ' ');
}