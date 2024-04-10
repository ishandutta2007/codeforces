#include<bits/stdc++.h>
using namespace std;
const int M=4e6+9;
int n,p;
int s[M];
int main(){
	scanf("%d%d",&n,&p);
	s[n]=1;
	for(int i=n-1;i>=1;--i){
		s[i]=s[i+1];
		for(int j=i+i;j<=n;j+=i){
			s[i]=((s[i]+s[j])%p+p-s[min(j+j/i,n+1)])%p;
		}
		if(i==1)printf("%d\n",s[1]);
		s[i]=(s[i]+s[i+1])%p;
	}
	return 0;
}