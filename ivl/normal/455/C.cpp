#include <cstdio>
#include <vector>

using namespace std;

int gr[300005];
int mp[300005];
int un(int a){
    if (gr[a] == a) return a;
    return gr[a] = un(gr[a]);
}

vector < int > veze[300005];

int n, m, q;

bool bio[300005];
int maks_path;

int dfs(int pos){
    ++bio[pos];
    int mb1 = 0, mb2 = 0;
    for (int i = 0; i < veze[pos].size(); ++i){
        int x = veze[pos][i];
        if (bio[x]) continue;
        int y = dfs(x);
        gr[x] = pos;
        if (y > mb2) mb2 = y;
        if (y > mb1){mb2 = mb1; mb1 = y;}
    }
    maks_path = max(maks_path, mb1 + mb2 + 1);
    return mb1 + 1;
}

void get(){
     int a;
     scanf("%d", &a);
     a = un(a);
     printf("%d\n", mp[a] - 1);
}

void merge(){
     int a, b;
     scanf("%d%d", &a, &b);
     a = un(a);
     b = un(b);
     if (a == b) return;
     gr[b] = a;
     int x = mp[a], y = mp[b], r = max(mp[a], mp[b]);
     x = x / 2 + 1;
     y = y / 2 + 1;
     r = max(r, x + y);
     mp[a] = r;
}

int main(){
    for (int i = 0; i <= 300000; ++i) gr[i] = i;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        veze[a].push_back(b);
        veze[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!bio[i]){
        dfs(i);
        mp[un(i)] = maks_path;
        //printf("%d\n", maks_path);
        maks_path = 0;
    }
    for (int i = 0; i < q; ++i){
        int t;
        scanf("%d", &t);
        if (t == 1) get();
        else merge();
    }
    return 0;
}