// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int H,L;
int main(){
    scanf("%d%d",&H,&L);
    printf("%.10lf\n",1.0*(1ll*L*L-1ll*H*H)/(H*2));
    return 0;
}