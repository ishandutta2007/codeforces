#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];
vector<int> p, q;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        if(p.empty()) p.push_back(a[i]);
        else if(q.empty()) q.push_back(a[i]);
        else {
            bool t1 = p[p.size() - 1] == a[i];
            bool t2 = q[q.size() - 1] == a[i];
            if(t1 && t2) return puts("NO"), 0;
            if(t1) q.push_back(a[i]);
            else p.push_back(a[i]);
        }
    }
    reverse(q.begin(), q.end());
    puts("YES");
    printf("%d\n", p.size());
    for(int &v : p) printf("%d ", v);
    printf("\n%d\n", q.size());
    for(int &v : q) printf("%d ", v);
    printf("\n");
    return 0;
}