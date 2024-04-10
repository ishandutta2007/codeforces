#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,k,a[105],b[105],it,u[105];
vector<int> v[105];
map<int,int> mp;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=-a[i];
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++){b[i]=-b[i];
	}
	for(i=1;i<=n;i++){
		memset(u,0,sizeof(u));
		mp.clear();
		for(j=1;j<=i;j++){
			mp[b[j]]++;
		}
		for(j=1;j<=i;j++){
			for(k=1;k<=n;k++){
				if(u[k]||!mp[a[k]]){continue;}mp[a[k]]--;
				v[i].push_back(a[k]);
				u[k]=1;break;
			}
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&i,&j);
		printf("%d\n",v[i][j-1]);
	}
}