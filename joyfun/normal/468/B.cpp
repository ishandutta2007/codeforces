#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a, b;
map<int, int> to;

struct Seq {
    int num, id, to, vis;
} s[N];

bool cmp(Seq a, Seq b) {
    return a.num < b.num;
}

bool cmpid(Seq a, Seq b) {
    return a.id < b.id;
}

int flag = 0;

bool solve() {
    int st = 0, ed = n - 1;
    while (st <= ed) {
        if (s[st].vis) {
            st++;
            continue;
        }
        if (s[ed].vis) {
            ed--;
            continue;
        }
        if (s[st].num + s[ed].num > b || s[st].num + s[ed].num < a)
            return false;
        if (s[st].num + s[ed].num == b) {
            s[st].vis = 1;
            s[ed].vis = 1;
            s[st].to = 1;
            s[ed].to = 1;
            st++;
            ed--;
            continue;
        } else if (s[st].num + s[ed].num == a) {
            s[st].vis = 0;
            s[ed].vis = 0;
            s[st].to = 0;
            s[ed].to = 0;
            st++;
            ed--;
        } else {
            if (!to.count(a - s[st].num)) return false;
            int v = to[a - s[st].num];
            if (s[v].vis) return false;
            s[v].to = 0;
            s[v].vis = 1;
            s[st].vis = 1;
            s[st].to = 0;
            st++;
        }
    }
    sort(s, s + n, cmpid);
    printf("YES\n");
    printf("%d", s[0].to^flag);
    for (int i = 1; i < n; i++)
        printf(" %d", s[i].to^flag);
    printf("\n");
    return true;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (a > b) {
        swap(a, b);
        flag = 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i].num);
        s[i].id = i;
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++)
        to[s[i].num] = i;
    if (!solve()) printf("NO\n");
    return 0;
}