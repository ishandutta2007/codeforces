#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[200500],x,y;
ll res;

int get2(int l1,int r1,int l2,int r2,int m){
	if(!m){return 0;}
	if(l1>r1||l2>r2){return 0x3f3f3f3f;}
	int i,j,k1=0,k2=0;
	for(i=l1;i<=r1;i++){if(b(m)&a[i]){k1=i;break;}}
	for(i=l2;i<=r2;i++){if(b(m)&a[i]){k2=i;break;}}
	if((!k1)&(k2==l2)||(!k2)&(k1==l1)){
		return b(m)+get2(l1,r1,l2,r2,m-1);
	}
	if(!k1){k1=r1+1;}
	if(!k2){k2=r2+1;}
	return min(get2(l1,k1-1,l2,k2-1,m-1),get2(k1,r1,k2,r2,m-1));
}

void get(int l,int r,int m){
	if(!m){return;}
	int i,j,k=0;
	for(i=l;i<=r;i++){
		if(b(m)&a[i]){k=i;break;}
	}
	if(k>l){
		res+=b(m)+get2(l,k-1,k,r,m-1);
		get(l,k-1,m-1);get(k,r,m-1);
	}
	else{get(l,r,m-1);}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	get(1,n,30);
	printf("%lld",res);
}