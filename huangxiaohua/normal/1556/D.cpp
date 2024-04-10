#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t;
ll res[20050],f[20050];

ll ask(int x,int y){
	ll r1,r2;
	r1=r2=0;
	printf("or %d %d\n",x,y);fflush(stdout);
	scanf("%lld",&r1);
	printf("and %d %d\n",x,y);fflush(stdout);
	scanf("%lld",&r2);
	return r1+r2;
}

void get(int l,int r){
	
	ll sum=0;
	int i,j,k;
	for(i=1;i<r;i++){
		f[i]=ask(i,i+1);
		sum+=f[i];
	}
	sum+=ask(1,r);
	sum/=2;
	for(i=2;i<=r;i+=2){
		sum-=f[i];
	}
	res[1]=sum;
	for(i=2;i<=r;i++){
		res[i]=f[i-1]-res[i-1];
	}
}

int main(){
	scanf("%d%d",&n,&m);
	if(n&1){
		get(1,n);
	}
	else{
		get(1,n-1);
		res[n]=ask(1,n)-res[1];
	}
	sort(res+1,res+n+1);
	printf("finish %lld",res[m]);
	fflush(stdout);
}