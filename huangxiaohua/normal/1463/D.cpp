#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,n,t,j,res,tmp1,tmp2,tmp;
bool a[400500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=2*n;i++){a[i]=0;}
		for(i=1;i<=n;i++){
			scanf("%d",&j);
			a[j]=1;
		}
		tmp=tmp1=tmp2=0;
		for(i=1;i<=2*n;i++){
			if(!a[i]){tmp++;}
			else{if(tmp){tmp--;tmp1++;}}
		}
		tmp=0;
		for(i=2*n;i>=1;i--){
			if(!a[i]){tmp++;}
			else{if(tmp){tmp--;tmp2++;}}
		}
		tmp2=n-tmp2;
		printf("%d\n",1+abs(tmp1-tmp2));
	}
}