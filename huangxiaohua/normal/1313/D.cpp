#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,it,res,sb[66],t1,used[666],vis3[100500];
int f[666],g[666];
map<int,vector<int> >q;
ll id[100500];
set<int> s;
map<int,int> len;
unordered_map<ll,int> vis,vis2;
#define b(x) (1<<((x)-1))

int main() {
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);
	//uniform_int_distribution<int>lim(1,n);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n>>k;
	q[n+1].push_back(0);
	for(i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		q[l].push_back(i);
		q[r+1].push_back(-i);
	}
	k=-1;
	for(auto [x,y]:q){
		if(k!=-1){
			len[k]=x-k;
		}
		k=x;
	}
	for(auto &[x,v]:q){
		//printf("NMSL%d %d\n",x,len[x]);
		if(x>n)break;
		memset(g,0,sizeof(g));
		for(auto i:v){
			if(i>0)continue;
			i=-i;
			for(int x1=0;x1<512;x1++){
				f[x1^id[i]]=max(f[x1^id[i]],f[x1]);
			}
			used[id[i]]=0;
			vis.erase(i);
		}
		vis2=vis;
		for(auto &i:v){
			if(i<0)continue;
			vis2[i]=1;
			for(j=1;;j*=2){
				if(!used[j]){
					used[j]=1;id[i]=j;break;
				}
			}
		}
		it=0;
		for(auto [i,j]:vis)vis3[i]=1;
		for(auto [i,j]:vis2){
			sb[++it]=i;
		}
		for(i=0;i<b(it+1);i++){
			ll tmp=0,tmp2=0;
			for(j=1;j<=it;j++){
				if((b(j)&i)&&vis3[sb[j]])tmp^=id[sb[j]];
				if((b(j)&i))tmp2^=id[sb[j]];
			}
			t1=f[tmp]+len[x]*(__builtin_popcount(i)&1);
			res=max(res,t1);
			g[tmp2]=t1;
		}
		for(auto [i,j]:vis)vis3[i]=0;
		swap(f,g);
		swap(vis,vis2);
		vis2.clear();
		
		//for(auto [x,y]:f){printf("a%lld %d\n",x,y);}
		//for(auto [y,z]:vis){printf("a%lld %d\n",x,y);}
	}
	cout<<res;
}