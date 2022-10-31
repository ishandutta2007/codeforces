#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,it0,it1,s0[200500],s1[200500],f[200500],lg[200500];
ll x,y,z,res;

vector<int> v[200500],num[200500];


void dfs(int x,int fa,int cl){
	if(cl){
		s1[++it1]=x;
	}
	else{
		s0[++it0]=x;
	}
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x,cl^1);
	}
}

int main(){
	cerr<<"TEST"<<'\n';
	
	for(i=1;i<=200005;i++){
		lg[i]=lg[i/2]+1;
	}
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		it0=it1=0;
		for(i=1;i<=n;i++){
			v[i].clear();
			f[i]=0;
		}
		
		for(i=1;i<n;i++){
			cin>>j>>k;
			v[j].push_back(k);
			v[k].push_back(j);
		}
		
		for(i=1;i<=20;i++){
			num[i].clear();
		}
		
		for(i=1;i<=n;i++){
			num[lg[i]].push_back(i);
		}
		
		dfs(1,0,0);
		
		//printf("NMSL%d %d\n",it1,it0);
		
		if(it1<=it0){
			for(i=20;i>=1;i--){
				if(num[i].size()<=it1){
					for(auto j:num[i]){
						f[s1[it1]]=j;
						it1--;
					}
					num[i].clear();
				}
			}
			for(i=20;i>=1;i--){
				for(auto j:num[i]){
					f[s0[it0]]=j;
					it0--;
				}
				num[i].clear();
			}
		}
		else{
			for(i=20;i>=1;i--){
				if(num[i].size()<=it0){
					for(auto j:num[i]){
						f[s0[it0]]=j;
						it0--;
					}
					num[i].clear();
				}
			}
			for(i=20;i>=1;i--){
				for(auto j:num[i]){
					f[s1[it1]]=j;
					it1--;
				}
				num[i].clear();
			}
		}
		
		for(i=1;i<=n;i++){
			cout<<f[i]<<' ';
		}
		cout<<'\n';
	}
}