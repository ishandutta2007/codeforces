#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,it,f[1005000][2],sb,a[1005000],l,r;

bool chk(int x){
	int mn=0,mx=0,i=0,j=0,k,t;
	for(t=18;t>=1;t--){
		sb=!!(x&b(t));
		if(f[i][sb])i=f[i][sb];
		else i=f[i][sb^1],mn|=b(t);
		
		if(f[j][sb^1])j=f[j][sb^1],mx|=b(t);
		else j=f[j][sb];
	}
	//printf("NMSL%d %d %d\n",x,mn,mx);
	return (mn==l&&mx==r);
}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		it=0;
		cin>>l>>r;
		for(i=l;i<=r;i++){
			cin>>k;a[i]=k;
			int cur=0;
			for(j=18;j>=1;j--){
				sb=!!(b(j)&k);
				if(!f[cur][sb])f[cur][sb]=++it;
				cur=f[cur][sb];
			}
		}
		for(i=l;i<=r;i++){
			if(chk(a[i]^l)){
				cout<<(a[i]^l)<<'\n';goto aaa;
			}
		}
		return 1;
		aaa:;
		memset(f,0,8*it+50);
	}
}