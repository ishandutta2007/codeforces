#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int v[10005];

vector < int > veze[10005];

bool cmp(int a, int b){return v[a] < v[b];}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", v + i);
    for (int i = 0; i < m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        veze[x].push_back(y);
        veze[y].push_back(x);
    }
    vector < int > v2;
    for (int i = 0; i < n; ++i) v2.push_back(i + 1);
    sort(v2.begin(), v2.end(), cmp);
    reverse(v2.begin(), v2.end());
    long long r = 0;
    for (int i = 0; i < v2.size(); ++i){
        int x = v2[i];
        for (int j = 0; j < veze[x].size(); ++j) r += v[veze[x][j]];
        v[x] = 0;
    }
    printf("%I64d\n", r);
    return 0;
}