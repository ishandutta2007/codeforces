#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,res,a[200500],del[200500],x,y;
vector<int> v[200500],ans;
vector<pair<int,int> >v2;
queue<int> q;
map<int,map<int,int> >mp;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(!a[x]){res++;}
		if(!a[y]){res++;}
		a[x]++;a[y]++;
		v2.push_back({x,y});
		v[x].push_back(y);
		v[y].push_back(x);
	}
	reverse(v2.begin(),v2.end());
	for(i=1;i<=n;i++){
		if(!a[i]){del[i]=1;continue;}
		if(a[i]<k){
			del[i]=1;res--;q.push(i);
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto i:v[x]){
			if(del[i]){continue;}
			a[i]--;
			if(a[i]<k){del[i]=1;res--;q.push(i);}
		}
	}
	for(auto [x,y]:v2){
		ans.push_back(res);
		
		if(!del[x]&&!del[y]){
			a[x]--;a[y]--;
			if(a[x]<k){del[x]=1;res--;q.push(x);}
			if(a[y]<k){del[y]=1;res--;q.push(y);}
		}
		mp[x][y]=mp[y][x]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(auto i:v[x]){
				if(del[i]||mp[i][x]){continue;}
				a[i]--;
				if(a[i]<k){del[i]=1;res--;q.push(i);}
			}
		}
	}
	for(i=m-1;i>=0;i--){
		printf("%d\n",ans[i]);
	}
}