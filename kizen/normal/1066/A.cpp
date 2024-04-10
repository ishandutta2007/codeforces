#include <bits/stdc++.h>

using namespace std;

int T;
int N, P, L, R;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &N, &P, &L, &R);
        printf("%d\n", N/P-(((R-R%P)-((L-L%P)+((L-L%P)<L? P:0)))/P+1));
    }
    return 0;
}