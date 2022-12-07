#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int w, h, n;
set<int> x[2];
multiset<int> xx[2];
char op[2];
int v;
set<int>::iterator it, l, r;
multiset<int>::iterator tmp;

long long gao(int tp) {
    x[tp].insert(v);
    it = x[tp].find(v);
    l = it; l--; r = it; r++;
    xx[tp].erase(xx[tp].find(*r - *l));
    xx[tp].insert(v - *l);
    xx[tp].insert(*r - v);
    long long ans = 1;
    tmp = xx[tp].end(); tmp--;
    ans *= *tmp;
    tmp = xx[!tp].end(); tmp--;
    ans *= *tmp;
    return ans;
}

int main() {
    scanf("%d%d%d", &w, &h, &n);
    x[0].insert(0); x[0].insert(w);
    x[1].insert(0); x[1].insert(h);
    xx[0].insert(w); xx[1].insert(h);
    while (n--) {
        scanf("%s%d", op, &v);
        printf("%lld\n", gao(op[0] == 'H'));
    }
    return 0;
}