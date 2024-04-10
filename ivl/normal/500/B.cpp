#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p[305];
char A[305][305];

bool bio[305]; vector < int > cr;
void dfs(int pos){
     bio[pos] = true;
     cr.push_back(pos);
     for (int i = 0; i < n; ++i){
         if (A[pos][i] == '1' && !bio[i]) dfs(i);
     }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", p + i);
    for (int i = 0; i < n; ++i){
        scanf("%s", A[i]);
    }
    for (int i = 0; i < n; ++i){
        if (bio[i]) continue;
        dfs(i);
        vector < int > v;
        for (int i = 0; i < cr.size(); ++i) v.push_back(p[cr[i]]);
        sort(v.begin(), v.end());
        sort(cr.begin(), cr.end());
        for (int i = 0; i < cr.size(); ++i) p[cr[i]] = v[i];
        cr.clear();
    }
    for (int i = 0; i < n; ++i) printf("%d ", p[i]);
    printf("\n");
    return 0;
}