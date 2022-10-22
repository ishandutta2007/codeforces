#include<bits/stdc++.h>
using namespace std;
int n,d,b,a[110000];
int solve(int n,int m){
	int now=0,ans=0,pos=1;
	for (int i=1;i<=m;i++){
		while (pos<=min(i+d*i,n)) now+=a[pos++];
		if (now>=b) now-=b;
		else ans++;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&d,&b); int m=(n+1)/2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int tmp=solve(n,m); reverse(a+1,a+n+1);
	printf("%d\n",max(tmp,solve(n,n-m)));
	return 0;
}