#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[100005];
int id[100005];

bool cmp(int x, int y){
     return a[x] < a[y];
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + (id[i] = i));
    sort(id, id + n, cmp);
    for (int i = 0; i < n - 2; ++i){
        if (a[id[i]] == a[id[i + 2]]){
           printf("YES\n");
           for (int j = 0; j < n; ++j) printf("%d ", id[j] + 1);
           printf("\n");
           swap(id[i], id[i + 1]);
           for (int j = 0; j < n; ++j) printf("%d ", id[j] + 1);
           printf("\n");
           swap(id[i], id[i + 2]);
           for (int j = 0; j < n; ++j) printf("%d ", id[j] + 1);
           printf("\n");
           return 0;
        }
    }
    int a = -1, b = -1;
    for (int i = 0; i < n - 1; ++i){
        if (::a[id[i]] == ::a[id[i + 1]]){b = a; a = i;}
    }
    if (b == -1){printf("NO\n"); return 0;}
    printf("YES\n");
    for (int i = 0; i < n; ++i) printf("%d ", id[i] + 1);
    printf("\n");
    swap(id[a], id[a + 1]);
    for (int i = 0; i < n; ++i) printf("%d ", id[i] + 1);
    printf("\n");
    swap(id[b], id[b + 1]);
    for (int i = 0; i < n; ++i) printf("%d ", id[i] + 1);
    printf("\n");
    
    return 0;
}