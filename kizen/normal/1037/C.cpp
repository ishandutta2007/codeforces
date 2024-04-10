#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e6+4;
int N;
char A[NS], B[NS];
int d[NS];

int main(){
    scanf("%d", &N);
    scanf("%s %s", A, B);

    d[0] = A[0]!=B[0];
    for(int i=1;i<N;++i){
        d[i] = d[i-1]+(A[i]!=B[i]);
        if(A[i-1]==B[i]&&A[i]==B[i-1]){
            if(i>1) d[i] = min(d[i], d[i-2]+1);
            else d[i] = min(d[i], 1);
        }
    }
    printf("%d", d[N-1]);

    return 0;
}