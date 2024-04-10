#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 222 + 10;
const int MM = 1e9 + 7;

int n;
int m;
int vis[MAXN][MAXN];
char s[111];

int __sec[MAXN];
int __in[MAXN];
vector<int> __e[MAXN];
int __fail = 0, __count = 0;

int init(int n) {
    for (int i = 1; i <= 2 * n; i++) __sec[i] = i;
    random_shuffle(__sec + 1, __sec + 2 * n + 1);
    for (int i = 1; i <= m; i++) cout << __sec[i] << ' '; cout << endl;
    for (int i = 1; i <= m; i++) __e[i].clear(), __in[i] = 0;
    __count = 0;
}

int Query(int p, int q) {
    assert(p != q);
#ifdef Arisa
    // cout << "query " << p << ' ' << q << endl;
    if (vis[p][q] == 0) {
        __count++;
    }
    int flag = (__sec[p] > __sec[q]) ? 1 : -1;
    vis[p][q] = flag;
    vis[q][p] = -flag;
    if (flag == -1) swap(p, q);
    __e[p].push_back(q);
    __in[q]++;
    return flag;
#else
    if (vis[p][q] == 0) {
        printf("? %d %d\n", p, q);
        fflush(stdout);
        scanf("%s", s);
        if (s[0] == '>') {
            vis[p][q] = 1, vis[q][p] = -1;
        }
        else {
            vis[q][p] = 1, vis[p][q] = -1;
        }
    }
    return vis[p][q];
#endif
}

int check() {
    set<PII> st;
    int notunique = 0;
    int valid = 1;
    for (int i = 1; i <= m; i++)
        if (__in[i] == 0) st.insert(PII(__sec[i], i));
    for (int i = 1; i <= n; i++) {
        if (st.size() == 0) {
            valid = 0;
            cerr << "sz = 0" << endl;
            break;
        }
        if (i == n && st.size() != 1) {
            valid = 0;
            cerr << "333 sz" << st.size() << endl;
            break;
        }
        if (st.size() >= 2) notunique = 1;
        auto u = st.begin()->second;
        st.erase(st.begin());
        if (__sec[u] <= n) {
            valid = 0;
            cerr << "555 " << __sec[u] << endl;
            break;
        }
        for (auto &v : __e[u]) {
            __in[v]--;
            if (__in[v] == 0) {
                st.insert(PII(__sec[v], v));
            }
        }
    }
    if (!notunique) cerr << "unique" << endl;
    if (!valid) cerr << "not valid" << endl;
    if (__count > 4 * n * n) cerr << "toooooooo many" << endl;
    return notunique && valid && __count <= 4 * n * n;
}

int Answer() {
#ifdef Arisa
    if (check()) cout << "YES" << endl;
    else {
        cout << "fuck" << endl;
        __fail += 1;
        // exit(0);
    }
#else
    puts("!");
    fflush(stdout);
#endif
}

void solve(int casi){
    //printf("Case #%d:", casi);
    scanf("%d", &n);
    m = 2 * n;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++)
            vis[i][j] = 0;
    }
#ifdef Arisa
    init(n);
#else
    ;
#endif
    vector<PII> f;
    for (int i = 1; i <= n; i++) {
        int o = Query(i * 2 - 1, i * 2);
        if (o == -1)
            f.emplace_back(i * 2 - 1, i * 2);
        else
            f.emplace_back(i * 2, i * 2 - 1);
    }
    while (f.size() != 3) {
        auto x = f.back(); f.pop_back();
        auto y = f.back(); f.pop_back();
        auto z = f.back(); f.pop_back();
        auto w = f.back(); f.pop_back();
        int o = Query(x.first, y.first);
        int p, q;
        if (o == -1) {
            f.push_back(y);
            p = x.second;
        }
        else {
            f.push_back(x);
            p = y.second;
        }
        o = Query(z.first, w.first);
        if (o == -1) {
            f.push_back(w);
            q = z.second;
        }
        else {
            f.push_back(z);
            q = w.second;
        }
        o = Query(p, q);
        if (o == -1) f.push_back(PII(p, q));
        else f.emplace_back(q, p);
    }
    auto x = f.back(); f.pop_back();
    auto y = f.back(); f.pop_back();
    auto z = f.back(); f.pop_back();
    int o = Query(x.first, y.first);
    if (o == 1) swap(x, y);
    o = Query(x.first, z.first);
    int A, B, C, D;
    if (o == -1) {
        A = x.second;
        int oo = Query(y.first, z.first);
        if (oo == -1) {
            B = y.second;
            C = z.first, D = z.second;
        }
        else {
            B = z.second;
            C = y.first;
            D = y.second;
        }
    }
    else {
        A = z.second;
        B = x.second;
        C = y.first;
        D = y.second;
    }
    o = Query(A, B);
    if (o == 1) swap(A, B);
    o = Query(A, C);
    if (o == 1) swap(A, C);
    // B C D
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != j && i != B && i != C && i != D && j != B && j != C && j != D) {
                Query(i, j);
            }
        }
    }
    Answer();
}

int main(){
    srand(time(NULL));
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        solve(i);
    // cerr << 1.0 * __fail / T << endl;
    return 0;
}