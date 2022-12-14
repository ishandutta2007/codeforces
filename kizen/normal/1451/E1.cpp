#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const int MOD = (int)1e9 + 7;
const int NS = (int)(1<<16) + 4;
int N;
int Xor[NS], ans[NS];

int main(){
    scanf("%d", &N);
    for(int i = 1; i < N; ++i){
        printf("XOR %d %d\n", i, i + 1); fflush(stdout);
        scanf("%d", Xor + i);
    }
    int val = 0;
    for(int i = 1; i < N; ++i){
        val ^= Xor[i];
    }
    Xor[N] = val;
    int a, b, c;
    puts("OR 1 3"); fflush(stdout);
    scanf("%d", &a);
    puts("OR 2 3"); fflush(stdout);
    scanf("%d", &b);
    puts("OR 1 2"); fflush(stdout);
    scanf("%d", &c);
    for(int i = 0; i < 16; ++i){
        if((1 << i) >= N){
            break;
        }
        if((Xor[1] & (1 << i)) && (Xor[2] & (1 << i))){
            if(a & (1 << i)){
                ans[1] |= (1 << i), ans[3] |= (1 << i);
            }
            else{
                ans[2] |= (1 << i);
            }
        }
        if((Xor[1] & (1 << i)) && !(Xor[2] & (1 << i))){
            if(b & (1 << i)){
                ans[2] |= (1 << i), ans[3] |= (1 << i);
            }
            else{
                ans[1] |= (1 << i);
            }
        }
        if(!(Xor[1] & (1 << i)) && (Xor[2] & (1 << i))){
            if(c & (1 << i)){
                ans[1] |= (1 << i), ans[2] |= (1 << i);
            }
            else{
                ans[3] |= (1 << i);
            }
        }
        if(!(Xor[1] & (1 << i)) && !(Xor[2] & (1 << i))){
            if(c & (1 << i)){
                ans[1] |= (1 << i), ans[2] |= (1 << i), ans[3] |= (1 << i);
            }
        }
        for(int j = 4; j <= N; ++j){
            ans[j] |= ((ans[j - 1] & (1 << i)) ^ (Xor[j - 1] & (1 << i)));
        }
    }
    printf("! ");
    for(int i = 1; i <= N; ++i){
        printf("%d ", ans[i]);
    }
    puts(""); fflush(stdout);
    return 0;
}