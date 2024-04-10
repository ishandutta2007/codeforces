#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,k,t,a[300500],res,b[300500],c1,c2;
char sb;
int main(){
	scanf("%d",&t);getchar();
	while(t--){
		scanf("%d",&n);getchar();c1=c2=0;res=n;
		for(i=1;i<=n;i++){
			scanf("%c",&sb);b[i]=0;
			if(sb=='-'){a[i]=0;}
			if(sb=='>'){a[i]=1;c1=1;}
			if(sb=='<'){a[i]=2;c2=1;}
		}
		if((c1+c2)<2){printf("%d\n",n);continue;}
		for(i=1;i<n;i++){
			if(a[i]&&a[i+1]){res--;}
		}
		if(a[n]&&a[1]){res--;}
		printf("%d\n",res);
	} 
}