#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m,x,a[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		int s=0;
		cin>>n>>x;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
			if(a[i]==x)s=1;
		if(s)puts("1");
		else{
			sort(a+1,a+1+n);
			printf("%d\n",max(2,x/a[n]+(x%a[n]>0?1:0)));
		}
	}
}