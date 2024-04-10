#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,d,m,n1,n2,l,r,len,sb;
ll res,a[100500],b[100500],tmp;

int main(){
	scanf("%d%d%d",&n,&d,&m);
	b[0]=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k<=m){a[++n1]=k;}
		else{b[++n2]=k;}
	}
	sort(a+1,a+1+n1);sort(b+1,b+1+n2);
	l=n1+1;r=n1;
	for(i=n;i>=1;i--){
		if(i==n){
			if(n2){res+=b[n2];n2--;continue;}
		}
		while(l&&(r-l+1)<(d+1)){l--;tmp+=a[l];}
		while((r-l+1)>(d+1)){tmp-=a[l];l++;}
		if(i>=d+1&&b[n2]>tmp){
			res+=b[n2];n2--;
			i-=d;
		}
		else{if(r){res+=a[r];tmp-=a[r];r--;}}
		//aaa:printf("%d %d %d\n",i,sb,res);
	}
	printf("%lld",res);
}