#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,a[5050];
int chk(int l,int r,int k){
	if(k>5000){return 114514;}
	int i,j,s[5050],m=0,res=0;;
	for(i=l;i<=r;i++){
		if(a[i]>k&&a[i-1]<=k){s[++m]=i;}
		if(a[i]>k&&a[i+1]<=k){s[++m]=i;}
	}
	if(!m){return 0;}
	for(i=1;i<=m;i+=2){
		res+=min(s[i+1]-s[i]+1,1+chk(s[i],s[i+1],k+1));
	}
	return res;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",chk(1,n,0));
}