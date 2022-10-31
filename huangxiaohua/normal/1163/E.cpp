#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,vis[300500],b[66],sb[66],a[200500];

void add(int x){
	int i,j,k=x;
	for(i=18;i>=1;i--){
		if(b(i)&x){
			if(b[i]){x^=b[i];}
			else{b[i]=x;sb[i]=k;return;}
		}
	}
}

void dfs(int x,int d){
	int i,j;
	printf("%d ",x);vis[x]=1;
	for(i=1;i<=d;i++){
		j=(x^sb[i]);
		if(!vis[j]){dfs(j,d);}
	}
}

bool chk(int x){
	int i,j,k;
	memset(sb,0,sizeof(sb));
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++){
		if(a[i]>=b(x+1)){continue;}
		add(a[i]);
	}
	for(i=1;i<=x;i++){
		if(!sb[i]){return 0;}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=18;i>=1;i--){
		if(chk(i)){
			printf("%d\n",i);
			dfs(0,i);return 0;
		}
	}
	puts("0\n0");
}