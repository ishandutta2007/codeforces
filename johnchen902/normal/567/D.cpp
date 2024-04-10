#include <set>
#include <cstdio>
#include <iterator>
using namespace std;
int main() {
    int n, k, a, m;
    scanf("%d %d %d %d", &n, &k, &a, &m);
    set<int> s;
    s.insert(0);
    s.insert(n + 1);
    int c = (n + 1) / (a + 1);
    for(int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        set<int>::iterator t = s.insert(x).first;
        c -= (*next(t) - *prev(t)) / (a + 1);
        c += (*next(t) - *t) / (a + 1);
        c += (*t - *prev(t)) / (a + 1);
        if(c < k) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
}