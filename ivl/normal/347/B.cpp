#include <cstdio>

using namespace std;

int n;
int a[100005];
bool x[100005];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int r = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == i){++r; x[i] = true;}
    int inc = 0;
    for (int i = 0; i < n; ++i){
        if (!x[i]){
           if (a[a[i]] == i){inc = 2; break;}
           inc = 1;
        }
    }
    printf("%d\n", r + inc);
    return 0;
}