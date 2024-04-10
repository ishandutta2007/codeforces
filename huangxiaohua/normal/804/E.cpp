#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005],b[1005],id[1005],vis[1005],vis2[1005],f[1005],it,mx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()+1);

void fuck1(){
	uniform_int_distribution<int>lim(1,n-1);
	memset(vis,0,sizeof(vis));
	vector<pair<int,int> >op;
	int i,j,k,t,pos,need,t1,fst;
	for(i=2;i<n;i++){
		op.push_back({n,i});
		swap(a[n],a[i]);
	}
	a[2]--;n--;
	swap(a[1],a[2]);
	for(t=1;t<=n;t++){
		memset(id,0,sizeof(id));
		for(i=1;i<=n;i++){
			vis2[i]=vis[i];
		}
		for(i=1;i<=n;i++){
			if(vis[i])continue;
			if(a[i]!=i){
				pos=i;need=a[i];break;
			}
		}
		if(t==1){
			pos=2;need=1;
		}
		m=0;
		for(i=1;i<=n;i++){
			if(!vis[i])f[++m]=i;
		}
		if(m==1){
			for(i=1;i<=n;i++){
				if(a[i]==1)a[i]=n+1;
				if(a[i]==n)a[i]=1;
			}
			op.push_back({1,n+1});
			swap(a[1],a[n+1]);
			op.push_back({1,n});
			swap(a[1],a[n]);
			break;
		}
		vis2[pos]=vis2[need]=1;
		fst=1;
		for(i=1;i<=(n-t-1)-(t==1);i++){
			while(1){
				k=lim(rng);
				if(vis2[k])continue;
				if(k==n&&need==1)continue;
				if(fst&&a[need]==k&&(t+2)!=n)continue;
				fst=0;
				op.push_back({need,k});
				swap(a[need],a[k]);
				vis2[k]=1;
				break;
			}
		}
		op.push_back({need,pos});
		swap(a[pos],a[need]);
		vis[need]=1;
	}
	n++;
	for(auto [x,y]:op){
		cout<<min(x,y)<<' '<<max(x,y)<<'\n';
	}
	for(i=1;i<=n;i++){if(a[i]!=i)exit(1);}
}

int main(){
	it=mx=0;
	cin>>n;
	for(i=1;i<=n;i++){
		a[i]=b[i]=i;
	}
	if(n==1){
		cout<<"YES\n";return 0;
	}
	k=0;
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)if(a[i]>a[j])k^=1;
	if(k!=(((n*n-n)/2)&1)){
		cout<<"NO\n";return 0;
	}
	cout<<"YES\n";
	fuck1();
}