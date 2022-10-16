#include<bits/stdc++.h>
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int main(void) {
    int n;
    scanf("%d",&n);
    int res=0;
    REP(love,n) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        res+=(x2-x1+1)*(y2-y1+1);
    }
    printf("%d\n",res);
    return 0;
}