#include <cstdio>
#include <set>
#include <map>
using namespace std;

struct S {
    set<int> s1;
    map<int, int> s2;
    S(int n) {
        s1.insert(0);
        s1.insert(n);
        s2[n] = 1;
    }
    int cut(int x) {
        auto a = s1.lower_bound(x);
        auto b = a--;
        if(!--s2[*b - *a])
            s2.erase(*b - *a);
        auto c = s1.insert(x).first;
        s2[*b - *c]++;
        s2[*c - *a]++;
        return (--s2.end())->first;
    }
};

int main() {
    int w, h, n;
    scanf("%d %d %d", &w, &h, &n);
    S sv(w), sh(h);
    for(int i = 0; i < n; i++) {
        char c[2]; int x;
        scanf("%1s %d", c, &x);
        if(c[0] == 'V')
            w = sv.cut(x);
        else
            h = sh.cut(x);
        printf("%I64d\n", w * 1ll * h);
    }
}