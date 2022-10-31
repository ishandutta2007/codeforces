#include<bits/stdc++.h>
using namespace std;

int i,j,t,n,sb[1055],tmp;
int main(){
    scanf("%d",&t);
    for(i=1;i<=t;i++){
		scanf("%d",&n);tmp=1145141919;
		for(j=1;j<=n;j++){
			scanf("%d",&sb[j]);
		}
		sort(sb+1,sb+1+n);
		for(j=2;j<=n;j++){
			tmp=min(tmp,sb[j]-sb[j-1]);
		}
		printf("%d\n",tmp);
    }
    return 0;
}