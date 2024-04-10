#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
int N;
int ans[NS * 4];

int main(){
    scanf("%d", &N); N *= 2;
    if(N / 2 % 2 == 0){
        puts("NO"); return 0;
    }
    for(int i = 1; i <= N; ++i){
        if(i % 4 == 1) ans[(i - 1) / 2 + 1] = i;
        else if(i % 4 == 2) ans[N / 2 + (i - 2) / 2 + 1] = i;
        else if(i % 4 == 3) ans[N / 2 + (i - 3) / 2 + 2] = i;
        else ans[(i - 4) / 2 + 2] = i;
    }
    puts("YES");
    for(int i = 1; i <= N; ++i) printf("%d ", ans[i]);
    return 0;
}