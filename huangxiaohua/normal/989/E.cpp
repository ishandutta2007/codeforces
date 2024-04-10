#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b;
double v[205][205],sb,v2[20][205][205],f[205],f2[205],ans,t1;
int x[205],y[205];
set<vector<int> >xian;

int main() {
	cin>>n;
	for(i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(i=1;i<=n;i++){
		map<pair<int,int>,vector<int> >mp;
		for(j=1;j<=n;j++){
			if(i==j)continue;
			int x1,y1;
			x1=x[i]-x[j];
			y1=y[i]-y[j];
			k=__gcd(x1,y1);
			x1/=k;y1/=k;
			if(x1<0)x1*=-1,y1*=-1;
			mp[{x1,y1}].push_back(j);
		}
		sb=1.0/mp.size();
		for(auto &[p,v0]:mp){
			v0.push_back(i);
			sort(v0.begin(),v0.end());
			xian.insert(v0);
			for(auto j:v0)v[j][i]+=sb/v0.size();
		}
	}
	memcpy(v2[0],v,sizeof(v2[0]));
	for(t=1;t<=13;t++){
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=1;k<=n;k++){
			v2[t][j][k]+=v2[t-1][j][i]*v2[t-1][i][k];
		}
	}
	cin>>t;
	while(t--){
		cin>>a>>b;
		b--;
		memset(f,0,sizeof(f));
		f[a]=1;
		for(k=0;k<=13;k++){
			if(!(b&(1<<k)))continue;
			memset(f2,0,sizeof(f2));
			for(i=1;i<=n;i++)for(j=1;j<=n;j++){
				f2[i]+=f[j]*v2[k][j][i];
			}
			memcpy(f,f2,sizeof(f2));
		}
		ans=t1=0;
		for(auto v:xian){
			sb=1.0/v.size();
			t1=0;
			for(auto i:v)t1+=f[i]*sb;
			ans=max(ans,t1);
		}
		printf("%.20lf\n",ans);
	}
}