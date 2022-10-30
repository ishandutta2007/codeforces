#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,x,y,a[200500],sum[200500];
map<int,map<int,int> >mp;
ll res;
int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);res+=a[i];
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&y,&k);
		i=mp[x][y];
		if(i){
			if(sum[i]<=a[i]){res++;}
			sum[i]--;
		}
		mp[x][y]=k;
		if(k&&sum[k]<a[k]){res--;}
		sum[k]++;
		printf("%lld\n",res);
	}
}