#include <bits/stdc++.h>

using namespace std;

int N;
int chk[1004];

int main(){
    scanf("%d", &N);
    mt19937 mtt(time(NULL));
    uniform_int_distribution < int > dis(1, N-1);
    int a, b, c, d, A, B, C, D = -1;
    for(int i=1;i<N;++i){
        int rd = dis(mtt);
        if(chk[rd]) --i;
        if(chk[rd]) continue;
        chk[rd] = 1;
        printf("? %d %d %d %d\n", 1, 1, N, rd); fflush(stdout);
        int num; scanf("%d", &num);
        if(num%2){
            a = b = 1, c = N, d = rd, A = 1, B = rd+1, C = D = N; break;
        }
    }
    memset(chk, 0, sizeof(chk));
    if(D==-1){
        for(int i=1;i<N;++i){
            int rd = dis(mtt);
            if(chk[rd]) --i;
            if(chk[rd]) continue;
            chk[rd] = 1;
            printf("? %d %d %d %d\n", 1, 1, rd, N); fflush(stdout);
            int num; scanf("%d", &num);
            if(num%2){
                a = b = 1, c = rd, d = N, A = rd+1, B = 1, C = D = N; break;
            }
        }
    }
    while(a<c){
        int mid = (a+c)/2;
        printf("? %d %d %d %d\n", a, b, mid, d); fflush(stdout);
        int num; scanf("%d", &num);
        if(num%2) c = mid;
        else a = mid+1;
    }
    while(A<C){
        int mid = (A+C)/2;
        printf("? %d %d %d %d\n", A, B, mid, D); fflush(stdout);
        int num; scanf("%d", &num);
        if(num%2) C = mid;
        else A = mid+1;
    }
    while(b<d){
        int mid = (b+d)/2;
        printf("? %d %d %d %d\n", a, b, c, mid); fflush(stdout);
        int num; scanf("%d", &num);
        if(num%2) d = mid;
        else b = mid+1;
    }
    while(B<D){
        int mid = (B+D)/2;
        printf("? %d %d %d %d\n", A, B, C, mid); fflush(stdout);
        int num; scanf("%d", &num);
        if(num%2) D = mid;
        else B = mid+1;
    }
    printf("! %d %d %d %d\n", a, b, A, B); fflush(stdout);
    return 0;
}