#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";

const int N = 1e6 + 20;
const int INF = 1e9 + 19;
const int ALF = 26;

struct Node {
    int go[ALF];
    vector < int > who[2];
    Node() { 
        memset(go, -1, sizeof(go));
    }
};

int n;
Node data[N];
char tmp[N];
int cur = 1;
int ans;
vector < pair < int, int > > answer;


void add(char * s, int type, int id) {
    int len = strlen(s);    
    int v = 0;
    for (int i = 0; i < len; i++) {
        int ch = s[i] - 'a';
        if (data[v].go[ch] == -1) {
            data[v].go[ch] = cur++;
        }
        v = data[v].go[ch];
    }
    data[v].who[type].pb(id);
}

pair < int, vector < int > * > merge(pair < int, vector < int > * > a, pair < int, vector < int > * > b, int h) {
    if (a.sc->size() > b.sc->size())
        swap(a, b);

    if (a.fr == b.fr) {
        for (int i = 0; i < (int)a.sc->size(); i++)
            b.sc->pb((*a.sc)[i]);
    }
    else {
        for (int i = 0; i < (int)a.sc->size(); i++) {
            ans += h;
            assert(!b.sc->empty());
            assert(a.fr != b.fr);
            int x = (*a.sc)[i];
            int y = b.sc->back();
            if (a.fr == 0)
                answer.pb(mp(x, y));
            else
                answer.pb(mp(y, x));

            b.sc->pop_back();
        }
    }

    return b;
}

pair < int, vector < int > * > dfs(int v, int h) {
    pair < int, vector < int > * > info = mp(0, new vector < int >()); 
    
    for (int i = 0; i < ALF; i++)
        if (data[v].go[i] != -1) {
            auto res = dfs(data[v].go[i], h + 1);
            info = merge(res, info, h);
        }
    
    vector < int > * tmp0 = new vector < int >();
    vector < int > * tmp1 = new vector < int >();
    for (auto x: data[v].who[0])
        tmp0->pb(x);
    for (auto x: data[v].who[1])
        tmp1->pb(x);

    info = merge(info, mp(0, tmp0), h);
    info = merge(info, mp(1, tmp1), h);

    return info;
}

void read() {
    scanf("%d", &n);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            scanf("%s", tmp);
            add(tmp, j, i);
        }
    }
    auto g = dfs(0, 0);
    assert(g.sc->empty());

    printf("%d\n", ans);
    for (auto x: answer)
        printf("%d %d\n", x.fr + 1, x.sc + 1);
}

void solve() {


}

void stress() {

}


int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    if (1) {
        int k = 1;         
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }



    return 0;
}