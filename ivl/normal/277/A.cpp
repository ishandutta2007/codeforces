#include <cstdio>
#include <vector>

using namespace std;

int m, n;

vector < int > budale[105];
vector < int > jezik[105];

bool bio[105];
bool b_j[105];

void dfs_2(int x);

void dfs(int x){
     if (bio[x]){
        return;
     }
     bio[x] = true;
     for (int i = 0; i < budale[x].size(); ++i){
         dfs_2(budale[x][i]);
     }
}

void dfs_2(int x){
     if (b_j[x]){
        return;
     }
     b_j[x] = true;
     for (int i = 0; i < jezik[x].size(); ++i){
         dfs(jezik[x][i]);
     }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        int pom;
        scanf("%d", &pom);
        for (int j = 0; j < pom; ++j){
            int pom2;
            scanf("%d", &pom2);
            budale[i].push_back(pom2);
            jezik[pom2].push_back(i);
        }
    }
    int rez = 0;
    for (int i = 0; i < n; ++i){
        if (!bio[i]){
           ++rez;
           dfs(i);
        }
    }
    for (int i = 1; i <= m; ++i){
        if (b_j[i]){
           --rez;
           break;
        }
    }
    printf("%d\n", rez);
    return 0;
}