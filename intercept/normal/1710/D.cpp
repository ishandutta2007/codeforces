#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=2e3+9;
int n;
set<int>s;
int a[M][M];
vector<int>v;
vector<pii>ans;
void work(){
	ans.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j)scanf("%1d",&a[i][j]);
	}
	s.clear();
	for(int i=1;i<=n+1;++i)s.insert(i);
	for(int l=2;l<=n;++l){
		for(int i=1;i+l-1<=n;++i){
			int j=i+l-1;
			if(a[i][j]){
				v.clear();
				auto it=s.upper_bound(i);
				it--;
				while((*it)<=j){
					v.eb(*it);
					it++;
				}
				if(v.size()==1)continue;
				for(auto o:v)s.erase(o);
				s.insert(v[0]);
				if(v.size()==2){
					ans.eb(i,j);
				}
				else{
					ans.eb(i,j);
					for(int k=2;k<v.size()-1;++k){
						int o=v[k];
						ans.eb(i,o);
					}
					ans.eb(v[1],j);
				}
			}
		}
	}
	for(auto o:ans)printf("%d %d\n",o.fi,o.se);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
5
10001
1000
100
10
1
*/