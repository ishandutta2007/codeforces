#include<bits/stdc++.h>
using namespace std;
const int N = 310;

vector<int> s[8];
int n;
int tar[N], chk[N];

inline int read(){
	int x=0;
	for(int i=0;i<3;i++){
		int s=0;scanf("%d",&s);
		x=x*2+s;
	}
	return x;
}

typedef pair<int,int> edge;
vector<int> t8;
vector<edge> mp;

bool B[N];int cur[N];
int g[8];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		tar[i]=read();
		if(i>1){
			s[tar[i]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		chk[i]=read();
	}
	if(s[7].size()){
		B[1]=0;cur[1]=7;
		for(size_t i=0;i<s[7].size();i++){
			mp.push_back(edge(1,s[7][i]));
			B[s[7][i]]=1;
			g[chk[s[7][i]]]=s[7][i];
			cur[s[7][i]]=7;
		}
	}else{
		B[1]=1;cur[1]=7;
		g[chk[1]]=1;
	}
	for(int i=7;i;i--)if(__builtin_popcount(i)==2){
		if(g[i]){
			for(size_t j=0;j<s[i].size();j++){
				cur[s[i][j]]=i;
				mp.push_back(edge(g[i],s[i][j]));
				B[s[i][j]]=1;
				if(!g[chk[s[i][j]]&i]){
					g[chk[s[i][j]]&i] = s[i][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cur[i]!=tar[i]){
			if(g[tar[i]]){
				mp.push_back(edge(g[tar[i]],i));
				cur[i]=tar[i];
			}else{
				for(int j=0;j<3;j++){
					if((1<<j)&tar[i]){
						if(g[1<<j]){
							mp.push_back(edge(g[1<<j],i));
							cur[i]|=1<<j;
						}
					}
				}
				if(cur[i]!=tar[i]){
					puts("Impossible");
					return 0;
				}
				B[i]=0;
				g[tar[i]]=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cur[i]!=tar[i]){
			puts("Impossible");
			return 0;
		}
	}
	puts("Possible");
	for(int i=1;i<=n;i++)printf("%d ",B[i]);puts("");
	cout << mp.size() << endl;
	for(size_t i=0;i<mp.size();i++){
		printf("%d %d\n",mp[i].first,mp[i].second);
	}
	return 0;
}