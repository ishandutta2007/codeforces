#include<bits/stdc++.h>
using namespace std;
int n,i,j,sb[200500],jb[200500],tmp,res,mx=1;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		sb[tmp]=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		jb[tmp]=sb[tmp]-i;
		if(jb[tmp]<0){jb[tmp]+=n;
		}
	}
	sort(jb+1,jb+n+1);
	tmp=jb[1];
	for(i=1;i<=n;i++){
		if(tmp==jb[i]){res++;}
		else{mx=max(mx,res);res=1;tmp=jb[i];
		}
	}mx=max(mx,res);
	printf("%d",mx);
}