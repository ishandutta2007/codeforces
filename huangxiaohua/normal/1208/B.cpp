#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r,a[2050],res,tmp;
map<int,int> mp;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n;i++){
		mp.clear();
		for(j=1;j<=i;j++){
			if(mp[a[j]]){goto aaa;}
			mp[a[j]]=1;
		}
		tmp=i;
		for(j=n;j>=i+1;j--){
			if(mp[a[j]]){break;}
			mp[a[j]]=1;
			tmp++;
		}
		res=max(res,tmp);
	}
	
	aaa:;
	printf("%d",n-res);
}