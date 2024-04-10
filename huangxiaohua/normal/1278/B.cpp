#include<bits/stdc++.h>
using namespace std;

int t,a,b,n,i;

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		t=abs(a-b);
		for(i=0;;i++){
			if(t<=i*(i+1)/2){
				if(t%2==i*(i+1)/2%2){printf("%d\n",i);break;}
			}
		}
	}
}