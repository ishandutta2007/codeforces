#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m, d, cnt;
int nxt[55], prv[55];
vector <int> v[MAXN], r[MAXN], g[MAXN*50], cmp, st;
vector < pair <int, int> > rek;
int bio[MAXN*50], val[MAXN*50];
bool opn[51][MAXN], flg[MAXN];

void precompute_nxt () {
    for (int i=0; i<d; i++) {
        nxt[i] = (i+1)%d;
        prv[i] = (i-1 + d) % d;
    }
}

void dfs1 (int xx) {
    rek.push_back(make_pair(xx, 0));
    while (!rek.empty()) {
        int x = rek.back().first, ind = rek.back().second;
        bio[x] = -1;
        int node = x / d, day = x % d;
        //cout << "bla " << node << " " << day << endl;
        bool called = 0;
        for (int i=ind; i<v[node].size(); i++) {
            int sus = v[node][i] * d + nxt[day];
            if (!bio[sus]) {
                rek[rek.size()-1].second = i+1;
                rek.push_back(make_pair(sus, 0));
                called = 1;
                break;
            }
        }
        if (called) {
            continue;
        } else {
            rek.pop_back();
        }
        st.push_back(x);
    }
}

void dfs2 (int xx) {
    rek.push_back(make_pair(xx, 0));
    while (!rek.empty()) {
        int x = rek.back().first, ind = rek.back().second;
        bio[x] = cnt;
        int node = x / d, day = x % d;
        cmp.push_back(x);
        flg[node] = 0;
        bool called = 0;
        for (int i=ind; i<r[node].size(); i++) {
            int sus = r[node][i] * d + prv[day];
            if (bio[sus] == -1) {
                rek[rek.size()-1].second = i+1;
                rek.push_back(make_pair(sus, 0));
                called = 1;
                break;
            } else if (bio[sus] < cnt) {
                g[bio[sus]].push_back(cnt);
            }
        }
        if (called) {
            continue;
        } else {
            rek.pop_back();
        }
        st.push_back(x);
    }
}

int calc_val () {
    int res = 0;
    for (int i=0; i<cmp.size(); i++) {
        int x = cmp[i];
        int node = x / d, day = x % d;
        //cout << node << " " << day << "  ";
        if (flg[node] == 0 && opn[day][node]) {
            res++;
            flg[node] = 1;
        }
    }
    return res;
}

void calc_dp () {
    for (int i=cnt; i>=1; i--) {
        int mx = 0;
        for (int j=0; j<g[i].size(); j++) {
            mx = max(mx, val[g[i][j]]);
        }
        val[i] += mx;
    }
}

void kosaraju () {
    for (int i=1; i<=n; i++) {
        for (int j=0; j<d; j++) {
            int x = i * d + j;
            if (!bio[x]) {
                dfs1(x);
            }
        }
    }
    int siz = st.size();
    for (int i = siz-1; i>=0; i--) {
        int x = st[i];
        if (bio[x] == -1) {
            cmp.clear();
            cnt++;
            dfs2(x);
            val[cnt] = calc_val();
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    precompute_nxt();
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        r[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<d; j++) {
            char c;
            cin >> c;
            opn[j][i] = (c == '1');
        }
    }
    kosaraju();
    calc_dp();
    cout << val[bio[d]];
    return 0;
}