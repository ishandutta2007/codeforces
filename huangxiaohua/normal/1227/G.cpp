#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,a1[1050],a0[1050];
bitset<1050> res[1050];

void work(int x,int l,int r){
	if(x>n){return;}
	if(l>r){return;}
	if(l==r){
		if(a1[x]>=a0[x]){
			res[l][x]=1;a1[x]--;
		}
		else{
			a0[x]--;
		}
		work(x+1,l,r);return;
	}
	
	int i,j,k,k1,k2,lim;
	k1=(r-l+1)/2;
	k2=(r-l+1)-k1;
	
	if(a1[x]>=k1&&a0[x]>=k2){
		for(i=l;i<=l+k1-1;i++){
			res[i][x]=1;
		}
		a1[x]-=k1;
		a0[x]-=k2;
		work(x+1,l,l+k1-1);
		work(x+1,l+k1,r);
		return;
	}
	
	if(a1[x]>=k2&&a0[x]>=k1){
		for(i=l;i<=l+k2-1;i++){
			res[i][x]=1;
		}
		a1[x]-=k2;
		a0[x]-=k1;
		work(x+1,l,l+k2-1);
		work(x+1,l+k2,r);
		return;
	}
	
	if(a1[x]<a0[x]){
		lim=min(r,l+a1[x]-1);
		for(i=l;i<=lim;i++){
			a1[x]--;
			res[i][x]=1;
		}
		for(i=lim+1;i<=r;i++){
			a0[x]--;
		}
		
		work(x+1,l,lim);
		work(x+1,lim+1,r);
	}
	else{
		lim=min(r,l+a0[x]-1);
		for(i=l;i<=lim;i++){
			a0[x]--;
		}
		for(i=lim+1;i<=r;i++){
			a1[x]--;
			res[i][x]=1;
		}
		work(x+1,l,lim);
		work(x+1,lim+1,r);
	}
	
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a1[i]);
		a0[i]=n+1-a1[i];
	}
	work(1,1,n+1);
	printf("%d\n",n+1);
	for(i=1;i<=n+1;i++){
		for(j=1;j<=n;j++){
			k=res[i][j];
			printf("%d",k);
		}puts("");
	}
}