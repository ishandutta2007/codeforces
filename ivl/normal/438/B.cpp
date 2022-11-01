#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long sq(long long x){return x * x;}

int n, m;
int a[100005];
vector < int > veze[100005];

bool cmp(int a, int b){return ::a[a] < ::a[b];}

int gr[100005], sz[100005];
int un(int a){
    if (gr[a] == a) return a;
    return gr[a] = un(gr[a]);
}
void join(int a, int b){
     a = un(a);
     b = un(b);
     if (a == b) return;
     gr[a] = b;
     sz[b] += sz[a];
     sz[a] = 0;
}
int size(int a){return sz[un(a)];}

int main(){
    for (int i = 0; i <= 100000; ++i) gr[i] = -1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        veze[x].push_back(y);
        veze[y].push_back(x);
    }
    vector < int > v2;
    for (int i = 0; i < n; ++i) v2.push_back(i);
    sort(v2.begin(), v2.end(), cmp);
    reverse(v2.begin(), v2.end());
    long long suma = 0;
    for (int i = 0; i < v2.size(); ++i){
        int x = v2[i];
        gr[x] = x;
        sz[x] = 1;
        suma -= a[x];
        for (int j = 0; j < veze[x].size(); ++j){
            int y = veze[x][j];
            if (gr[y] == -1) continue;
            if (un(y) == un(x)) continue;
            suma -= sq(size(y)) * a[x];
            join(y, x);
        }
        suma += sq(size(x)) * a[x];
    }
    printf("%lf\n", (double)suma / (double)n / (double)(n - 1));
    return 0;
}