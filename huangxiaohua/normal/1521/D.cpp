#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,sb;
vector<int> v[100500];
vector<pair<int,int> >r1,r2;
unordered_map<int,unordered_map<int,int> >del;

int dfs(int x,int fa){
	int sb=x,cnt=0,tmp;
	for(auto i:v[x]){
		if(i==fa){continue;}
		tmp=dfs(i,x);
		if(del[i][x]){continue;}
		cnt++;
		if(cnt==2){
			r2.push_back({sb,tmp});
			sb=tmp;continue;
		}
		if(cnt>=3){
			r1.push_back({i,x});
			r2.push_back({i,tmp});
			del[x][i]=del[i][x]=1;
			continue;
		}
		sb=tmp;
	}
	if(fa&&cnt>=2){
		r1.push_back({x,fa});
		del[x][fa]=del[fa][x]=1;
		return 0;
	}
	if(!fa&&cnt<2){r2.push_back({1,sb});}
	return sb;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		r1.clear();r2.clear();del.clear();
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		k=r1.size();
		printf("%d\n",k);
		for(i=0;i<k;i++){
			printf("%d %d %d %d\n",r1[i].first,r1[i].second,r2[i].second,r2[i+1].first);
		}
	}
}