#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
using namespace std;
const int N = 105000;
char str[N];

int read(void) {
    int x = 0; char c = getchar();
    while (!isdigit(c)) c=getchar();
    for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x;
}

struct Seg {
    int ls, rs;
    int sum;
    #define ls(x) tree[x].ls
    #define rs(x) tree[x].rs
    #define sum(x) tree[x].sum
}tree[N<<5];

set<int> s;
int cnt, n, m;
int flag[N], T[N];

void update(int &x, int l, int r, int d) {
    if (!x) x = ++cnt; sum(x)++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (d <= mid) update(ls(x), l, mid, d);
    else update(rs(x), mid + 1, r, d);
}

int merge(int x,int y) {
    if (!x || !y) return x | y;
    sum(x) += sum(y);
    ls(x) = merge(ls(x), ls(y));
    rs(x) = merge(rs(x), rs(y));
    return x;
}

void tear(int &x, int y, int k, int tag) {
    if (sum(y) == k) return;
    x = ++cnt; sum(x) = sum(y) - k, sum(y) = k;
    if (!sum(ls(y)) && !sum(rs(y))) return;
    if (tag) swap(ls(y), rs(y)), swap(ls(x), rs(x));
    if (k <= sum(ls(y))) tear(ls(x), ls(y), k, tag), rs(x) = rs(y), rs(y) = 0;
    else tear(rs(x), rs(y), k - sum(ls(y)), tag);
    if (tag) swap(ls(y), rs(y)), swap(ls(x), rs(x));
}

set<int> :: iterator split(int pos) {
    set<int> :: iterator it = s.lower_bound(pos);
    if (it != s.end() && *it == pos) return it;
    --it; tear(T[pos], T[*it], pos - (*it), flag[pos] = flag[*it]);
    return s.insert(pos).first;
}

int ans[50];
void query(int l, int r, int x) {
    if (l == r || sum(x) == 0) return (void)(ans[l] += sum(x));
    int mid = (l + r) >> 1;
    if (ls(x)) query(l, mid, ls(x));
    if (rs(x)) query(mid + 1, r, rs(x)); 
}

void out(int cnt, int a) {
    while (cnt--) putchar(a + 'a');
}

int main() {
    n = read(), m = read();
    scanf ("%s", str + 1);
    for (int i = 1;i <= n; i++) {
        update(T[i], 0, 25, str[i]-'a');
        s.insert(i);
    }
    set<int> :: iterator it, it1, it2;
    for (int i = 1;i <= m; i++) {
        int l = read(), r = read(), opt = read() ^ 1;
        it1 = split(l), it2 = split(r+1);
        // cout << s.size() << endl;
        for (it = ++it1;it != it2; it++) T[l] = merge(T[l], T[*it]);
        flag[l] = opt; s.erase(it1, it2);
    }
    while (s.size()) {
        it = s.begin();  
        memset(ans, 0, sizeof(ans));
        query(0, 25, T[*it]);
        if (!flag[*it]) for (int i = 0;i < 26; i++) out(ans[i], i);
        else for (int i = 25;i >= 0; i--) out(ans[i], i);
        s.erase(it);
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

1 4 0
3 6 0
7 10 1

*/