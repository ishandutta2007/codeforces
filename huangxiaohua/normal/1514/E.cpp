#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,a[150],ans[105][105],cnt;
bool ask(int x,int y){
	printf("1 %d %d\n",a[x]-1,a[y]-1);fflush(stdout);
	scanf("%d",&x);return x;
}

void sort2(int l,int r){
	if(l>=r){return;}
	int k=(r+l)/2,i=l,j=k+1,it=l-1,tmp[150];
	sort2(l,k);sort2(k+1,r);
	while(i<=k||j<=r){
		if(i>k){tmp[++it]=a[j];j++;continue;}
		if(j>r){tmp[++it]=a[i];i++;continue;}
		if(ask(i,j)){tmp[++it]=a[i];i++;}
		else{tmp[++it]=a[j];j++;}
	}
	for(int i=l;i<=r;i++){
		a[i]=tmp[i];
	}
}

bool ask2(int l,int r){
	if(!l){return 0;}
	printf("2 %d %d",a[r]-1,l);
	for(int i=1;i<=l;i++){
		printf(" %d",a[i]-1);
	}
	puts("");fflush(stdout);
	scanf("%d",&r);return r;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);cnt=0;
		memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++){
			a[i]=i;ans[i][i]=1;
		}
		sort2(1,n);
		
		int l=n-1,r=n,r1=n;
		for(;l>=0;l--){
			while(r1>l&&!ask2(l,r1)){
				r1--;
			}
			if(r1>l){continue;}
			for(i=r1+1;i<=r;i++){
				for(j=r1+1;j<=n;j++){ans[a[i]][a[j]]=1;}
			}
			r=r1=l;
		}
		puts("3");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d",ans[i][j]);
			}puts("");
		}
		fflush(stdout);
		scanf("%*d");
	}
}