#include<bits/stdc++.h>
using namespace std;

int i,j,m,a,b,c,d;
int main(){
    scanf("%d",&m);
    for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		c=max(a,b);d=min(a,b);
		c=max(c,d*2);
		printf("%d\n",c*c);
    }
    return 0;
}