#include <bits/stdc++.h>

using namespace std;

int N, k;
int A[1004], B[1004];

int main(){
    scanf("%d %d", &N, &k);
    for(int i=1;i<=N;++i) scanf("%d", A+i);
    for(int i=1;i<=N;++i) scanf("%d", B+i);
    if(A[1]&&A[k]) puts("YES");
    else{
        int f = 0;
        for(int i=k+1;i<=N;++i) if(A[i]&&B[i]) f = 1;
        if(A[1]&&f&&B[k]) puts("YES");
        else puts("NO");
    }
    return 0;
}