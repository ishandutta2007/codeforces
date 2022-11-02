#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[105],b[105],par[105],where[105];

int Find (int A) {
    if(par[A]==A) return A;
    return par[A] = Find(par[A]);
}

void Union (int A,int B) {
    A = Find(A); B = Find(B);
    par[A] = B;
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        where[a[i]] = i;
        par[i] = i;
    }
    for(i=1;i<=n;i++) scanf("%d",&b[i]);
    for(i=1;i<=n;i++){
        if(i-b[i]>0) {
            Union(i,i-b[i]);
        }
        if(i+b[i]<=n) {
            Union(i,i+b[i]);
        }
    }
    for(i=1;i<=n;i++) {
        if(Find(i) != Find(where[i])){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}