#include<bits/stdc++.h>
using namespace std;

int n,i,t,a[125],tmp,k,an,res;
char sb[150];
int main(){
    scanf("%d\n",&t);
    while(t--){
    	gets(sb+1);
    	n=strlen(sb+1);tmp=an=res=0;
    	memset(a,0,sizeof(a));
    	for(i=1;i<=n;i++){
    		k=sb[i]-'0';
    		if(k==1){tmp++;}
    		else{
				if(tmp){an++;a[an]=tmp;tmp=0;}
			}
		}
		if(tmp){an++;a[an]=tmp;tmp=0;}
		sort(a+1,a+1+an);
		for(i=an;i>=1;i-=2){
			res+=a[i];
		}
    	printf("%d\n",res);
	}
}