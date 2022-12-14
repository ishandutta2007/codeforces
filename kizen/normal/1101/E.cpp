#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int l = 0, r = 0;
    while(N--){
        char c; int a, b;
        scanf(" %c %d %d", &c, &a, &b);
        if(c=='+'){
            l = max(l, min(a, b)), r = max(r, max(a, b));
        }
        else{
            if(a>=l&&b>=r) puts("YES");
            else if(a>=r&&b>=l) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}