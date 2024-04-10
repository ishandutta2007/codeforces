// Hydro submission #61daab3c3aa9cfeed584cfd2@1641720637423
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],max1=1,s[N],b[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>m)continue;
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;i*j<=m;j++){
			s[i*j]+=b[i];
			if(s[i*j]>s[max1])max1=i*j;
		}
	}
	printf("%d %d\n",max1,s[max1]);
	for(int i=1;i<=n;i++)if(max1%a[i]==0)printf("%d ",i);
}