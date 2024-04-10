#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[300500],f[300500],s1[300500],s2[300500],m1,m2;

int main(){
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);f[1]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		f[i]=min(f[i],f[i-1]+1);
		while(m1&&a[s1[m1]]>=a[i]){if(a[s1[m1]]!=a[i]){f[i]=min(f[i],f[s1[m1-1]]+1);}m1--;}s1[++m1]=i;
		while(m2&&a[s2[m2]]<=a[i]){if(a[s2[m2]]!=a[i]){f[i]=min(f[i],f[s2[m2-1]]+1);}m2--;}s2[++m2]=i;
	}
	printf("%d",f[n]);
}