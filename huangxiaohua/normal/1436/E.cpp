#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[100500],f[500500],lst[100500],sb;

void upd(int x,int l,int r,int pos,int v){
	int md=(l+r)/2;
	if(l==r){f[x]=v;return;}
	if(pos<=md){upd(x*2,l,md,pos,v);}
	else{upd(x*2+1,md+1,r,pos,v);}
	f[x]=min(f[x*2],f[x*2+1]);
}

int get(int x,int l,int r,int al,int ar){
	int md=(l+r)/2;
	if(l>ar||r<al){return 2e9;}
	if(al<=l&&r<=ar){return f[x];}
	return min(get(x*2,l,md,al,ar),get(x*2+1,md+1,r,al,ar));
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k!=1){
			res[1]=1;sb=get(1,1,n,1,k-1);
			if(sb>lst[k]){res[k]=1;}
		}
		upd(1,1,n,k,i);lst[k]=i;
	}
	for(i=2;i<=n+1;i++){
		if(get(1,1,n,1,i-1)>lst[i]){res[i]=1;}
	}
	for(i=1;;i++){
		if(!res[i]){printf("%d",i);return 0;}
	}
}