#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[4050],len;
priority_queue<int> q;

int chk(int l,int r){
	int res=0x7fffffff,i,j,len=n-m+1;
	for(i=l;i+len-1<=r;i++){
		//printf("a%d %d %d %d\n",l,r,i,i+len-1);
		res=min(res,max(a[i],a[i+len-1]));
	}
	return res;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		len=max(n-m+1,n-k);
		res=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i+len-1<=n;i++){
			res=max(res,chk(i,i+len-1));
		}
		printf("%d\n",res);
	}
}