#include<bits/stdc++.h>
using namespace std;
int i,t,a,b,c,d,e,f,k,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d%d",&c,&b,&a,&f,&e,&d);
		res=0;
		k=min(a,e);
		res+=2*k;
		a-=k;e-=k;
		
		k=min(d,c);
		d-=k;c-=k;
		
		k=min(d,a);
		d-=k;a-=k;
		
		k=min(b,e);
		b-=k;e-=k;
		
		k=min(b,f);
		b-=k;f-=k;
		
		res-=2*min(d,b);
		printf("%d\n",res);
	}
}