#include<bits/stdc++.h>
using namespace std;
int n, cur;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int tmp;
        char x[10];
        scanf("%d%s",&tmp,x);
        if(x[0] == 'S') {
            cur += tmp;
        }
        else if(x[0] == 'N') {
            cur -= tmp;
        }
        else if(cur == 0 || cur == 20000) {puts("NO"); return 0;}
        if(cur < 0 || cur > 20000) {puts("NO"); return 0;}
    }
    if(cur) {puts("NO"); return 0;}
    puts("YES");
}