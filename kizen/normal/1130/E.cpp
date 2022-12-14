#include <bits/stdc++.h>

using namespace std;

int N;
int ans[2004];

int main(){
    ans[2] = -1;
    scanf("%d", &N);
    int i;
    for(i=3;i<=2000;i++) if(N%2==i%2){
        if((i-2)*(int)1e6>=(N+i)/2) break;
    }
    if(i==2001){
        puts("-1"); return 0;
    }
    int val = (N+i)/2;
    for(int j=3;j<=i;++j){
        ans[j] = min((int)1e6, val);
        val -= ans[j];
    }
    printf("%d\n", i);
    for(int j=1;j<=i;++j) printf("%d ", ans[j]);
    return 0;
}