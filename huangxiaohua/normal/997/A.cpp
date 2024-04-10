#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,a,x,y,k,res1,res2,tmp,tmp2=1;

int main(){
	scanf("%d%d%d",&a,&x,&y);
	for(i=1;i<=a;i++){
		scanf("%1d",&tmp);
		if(tmp==0){k+=tmp2;tmp2=0;}
		else{tmp2=1;}
	}
	res1=k*y;
	res2=(k-1)*x+y;
	if(res2<0){res2=0;}
	printf("%lld",min(res1,res2));
}