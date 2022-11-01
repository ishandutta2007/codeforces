#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;

bool has[512 * 1024 * 2 - 1];
int seg[512 * 1024 * 2 - 1];

void init() {
    has[0] = true;
    seg[0] = 0;
}

void edit(int l, int r, int x, int nl = 0, int nr = 512 * 1024, int k = 0) {
    if(l <= nl && nr <= r) {
        has[k] = true;
        seg[k] = x;
    } else if(!(r <= nl || nr <= l)) {
        if(has[k]) {
            has[k] = false;
            has[2 * k + 1] = true; seg[2 * k + 1] = seg[k];
            has[2 * k + 2] = true; seg[2 * k + 2] = seg[k];
        }
        edit(l, r, x, nl, (nl + nr) / 2, 2 * k + 1);
        edit(l, r, x, (nl + nr) / 2, nr, 2 * k + 2);
    }
}

int query(int i, int nl = 0, int nr = 512 * 1024, int k = 0) {
    if(has[k])
        return seg[k];
    else if(i < (nl + nr) / 2)
        return query(i, nl, (nl + nr) / 2, 2 * k + 1);
    else
        return query(i, (nl + nr) / 2, nr, 2 * k + 2);
}

struct X {
    int c, e, l;
};

vector<int> ans;
map<int, X> mp;

void found(int a, int b) {
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(a);
    ans.push_back(b);
    mp.clear();
    init();
}

int main(){
    int n;
    scanf("%d", &n);
    init();

    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if(!mp.count(a)) {
            mp[a] = {1, i, i};
        } else {
            X x = {mp[a].c + 1, mp[a].e, i};
            mp[a] = x;
            if(x.c >= 4) {
                found(a, a);
            } else if(x.c >= 2) {
                if(query(x.e) && query(x.e) != a)
                    found(query(x.e), a);
                else
                    edit(x.e, x.l, a);
            }
        }
    }

    printf("%d\n", (int) ans.size());
    for(int i = 0; i < (int) ans.size(); i++)
        printf("%d%c", ans[i], i == (int) ans.size() - 1 ? '\n' : ' ');
}