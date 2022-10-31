#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[3050],res[305000],it;

void swp(int x){
	res[++it]=x;int l=1,r=x;while(l<r){swap(a[l],a[r]);l++;r--;}
}

void get(int y,int x){//x:ji y:ou
	int i,j,k,px,py;
	for(i=1;i<=n;i++){
		if(a[i]==x){px=i;}
		if(a[i]==y){py=i;}
	}
	if(abs(px-py)!=1){
		if(px<py){swp(px);swp(py-1);px=py-1;}
		else{swp(px);py=(px+1-py);swp(py-1);px=py-1;}
	}
	if(px+1==py){
		swp(py+1);swp(3);swp(x);
	}
	else{
		swp(px);swp(x);
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			if((a[i]&1)!=(i&1)){
				puts("-1");goto aaa;
			}
		}
		it=0;
		for(i=n;i>1;i-=2){
			get(i-1,i);
		}
		printf("%d\n",it);
		for(i=1;i<=it;i++){
			printf("%d ",res[i]);
		}puts("");
		aaa:;
	}
}