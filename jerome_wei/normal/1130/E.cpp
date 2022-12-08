#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int sub,n;
int a[N];
int main()
{
	scanf("%d",&sub);
	a[1]=-1;
	for(int l=1;l<N;l++){
		if(l*1000000>=sub+(l+1)){
			n=l+1;break;
		}
	}
	sub+=n;
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		if(i==1)a[i]=-1;
		else a[i]=min(sub,1000000);
		if(i>1)sub-=a[i];
	}
	for(int i=n;i>1;i--){
		if(a[i]){
			a[i]-=min(sub,a[i]-1);
			sub-=min(sub,a[i]-1);
		}
		if(!a[i]){
			a[i]++;
			sub++;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
}