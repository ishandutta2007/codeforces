#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,a[100500],sb,y;
bool vis[100500];
ll res=0;
vector<int> s1,s2;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main(){
	t=1;
	vector<int> f(100005),g(100005);
	scanf("%d",&t);
	while(t--){
		res=0;
		s2.clear();
		s1.clear();
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		f[a[n]]=1;s1.push_back(a[n]);
		int nmsl=0;
		for(i=n-1;i>=1;i--){
			for(auto x:s1){
				y=f[x];
				if(!y)continue;
				k=(a[i]/x);
				if(!k)k++;
				while((a[i]+k-1)/k>x)k++;
				sb=a[i]/k;
				if(!vis[sb])s2.push_back(sb);
				vis[sb]=1;
				g[sb]=su(g[sb],y);
				res=su(res,1ll*(k-1)*y%M*i%M);
			}
			swap(s1,s2);
			swap(f,g);
			for(auto i:s2)g[i]=0;
			s2.clear();
			if(i!=1)f[a[i]]++;
			if(i!=1&&!vis[a[i]])s1.push_back(a[i]);
			for(auto i:s1)vis[i]=0;
		}
		for(auto i:s1)f[i]=0;
		printf("%lld\n",res);
	}
}