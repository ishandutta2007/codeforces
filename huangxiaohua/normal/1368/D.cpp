#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
 
ll res,tmp;
int i,j,k,a[25],b[25],n;
 
int main(){
	for(i=0;i<=20;i++){
		b[i]=pow(2,i);
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&tmp);
		j=0;
		while(tmp){
			if(tmp%2){a[j]++;}
			tmp/=2;j++;
		}
	}
	//for(i=0;i<=20;i++){printf("%d %d\n",b[i],a[i]);}
	while(1){
		tmp=0;
		for(i=0;i<=20;i++){
			if(a[i]!=0){
				a[i]--;
				tmp+=b[i];
			}
		}
		res+=tmp*tmp;
		if(tmp==0){break;}
	}
	printf("%llu",res);
}