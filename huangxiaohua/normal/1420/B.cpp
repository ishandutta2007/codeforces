#include<bits/stdc++.h>
using namespace std;
 
int l2(int a){
	int res=0;
	while(a){
		res++;a>>=1;
	}
	return res;
}

int i,n,a[100500],t;
long long res,b[50];

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);res=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i]=l2(a[i]);
		}
		for(i=1;i<=n;i++){
			res+=b[a[i]];b[a[i]]++;
		}
		printf("%lld\n",res);
	}
}