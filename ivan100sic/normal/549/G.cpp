#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int A[200005],N;

int main(){
    scanf("%d",&N);
    for (int i=1; i<=N; i++){
        scanf("%d",A+i);
        A[i]+=i;
    }
    sort(A+1,A+N+1);
    for (int i=1; i<=N; i++) A[i]-=i;
    for (int i=1; i<N; i++){
        if (A[i]>A[i+1] || A[i]<0 || A[i+1]<0){
            printf(":(\n");
            return 0;
        }
    }
    for (int i=1; i<=N; i++) printf("%d%c",A[i],i==N?'\n':' ');
    return 0;
}