#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,md,l,r,tmp,a[1005000],b[1005000];
int get(int x){
	int i,j,k,cur=x;
	for(i=2;i<=n;i++){
		cur=min(b[i],cur-a[i]+b[i]);
		if(cur<0)return -1;
	}
	return cur;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)scanf("%d",&b[i]);
		l=0;r=b[1];
		while(l<=r){
			md=(l+r)/2;
			tmp=get(md);
			if(tmp==-1)l=md+1;
			else{
				r=md-1;
				if((tmp+b[1]-md)>=a[1]){
					cout<<"YES\n";goto aaa;
				}
			}
		}
		cout<<"NO\n";
		aaa:;
	}
}