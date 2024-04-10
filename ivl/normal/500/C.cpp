#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int w[505];
int b[1005];

vector < int > ord;
bool bio[505];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", w + i);
    for (int i = 1; i <= m; ++i) scanf("%d", b + i);
    for (int i = 1; i <= m; ++i){
        if (bio[b[i]]) continue;
        bio[b[i]] = true;
        ord.push_back(b[i]);
    }
    for (int i = 1; i <= n; ++i) if (!bio[i]) ord.push_back(i);
    int r = 0;
    for (int i = 1; i <= m; ++i){
        //for (int i = 0; i < n; ++i) printf("%d ", ord[i]); printf("\n");
        int x = b[i];
        int y = -1; for (int i = 0; i < ord.size(); ++i) if (ord[i] == x) y = i;
        for (int i = 0; i < y; ++i) r += w[ord[i]];
        ord.erase(ord.begin() + y);
        ord.insert(ord.begin(), x);
    }
    printf("%d\n", r);
    return 0;
}