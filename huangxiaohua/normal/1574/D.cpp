#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[11][200500],num[11],mx=-1;
vector<int> res,v,v0[100500];
map<vector<int>,bool> mp;

void show(){for(auto i:res){printf("%d ",i);}exit(0);}
int cal(){int i,res=0;for(i=1;i<=n;i++){res+=a[i][v[i-1]];}return res;}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num[i]);
		for(j=1;j<=num[i];j++){
			scanf("%d",&a[i][j]);
		}
		res.push_back(num[i]);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		for(v.clear(),j=1;j<=n;j++){
			scanf("%d",&k);v.push_back(k);
		}
		mp[v]=1;v0[i]=v;
	}
	if(!mp.count(res))show();
	for(t=1;t<=m;t++){
		v=v0[t];
		for(i=1;i<=n;i++){
			if(v[i-1]<=1)continue;
			v[i-1]--;k=cal();
			if(k<mx||mp.count(v)){v[i-1]++;continue;}
			mx=k;res=v;v[i-1]++;
		}
	}
	show();
}