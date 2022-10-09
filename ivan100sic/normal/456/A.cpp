#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct p{
    int a,b;
    inline friend bool operator <(p u,p v){
        return u.a<v.a;
    };
};

p A[100005];
int N,i;

int main(){
    scanf("%d",&N);
    for (i=1; i<=N; i++) scanf("%d%d",&A[i].a,&A[i].b);
    sort(A+1,A+N+1);
    for (i=2; i<=N; i++) if (A[i].b < A[i-1].b){
        printf("Happy Alex\n");
        return 0;
    }
    printf("Poor Alex\n");
    return 0;
}