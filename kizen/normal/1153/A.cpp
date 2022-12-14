#include <bits/stdc++.h>

using namespace std;

int N, T;
int ans, low = (int)1e9;

int main(){
    scanf("%d %d", &N, &T);
    int i = 1;
    while(N--){
        int a, b; scanf("%d %d", &a, &b);
        if(a+max(0, ((T-a)/b+((T-a)%b>0))*b)-T<low){
            low = a+max(0, ((T-a)/b+((T-a)%b>0))*b)-T, ans = i;
        }
        ++i;
    }
    printf("%d\n", ans);
    return 0;
}