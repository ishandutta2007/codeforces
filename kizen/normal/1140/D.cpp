#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    scanf("%d", &N);
    int ans = 0;
    for(int i=2;i<N;++i) ans += i*(i+1);
    printf("%d\n", ans);
    return 0;
}