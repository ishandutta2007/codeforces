#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 1000

int i,j,k,n,m,t,it,id[500500],it1,it2;
ll f[4][500500],g[500500],b[505000],b2[500500],b3[500500],ans=-1e18,t1;
vector<tuple<int,int,int> >q,v[500500];
void work(int l,int r,int id){
	ll pre=-1e18;
	int i,j,k;
	for(i=l;i<=r;i++){
		pre=max(pre,f[1][i]);
		g[i]=max({g[i],b[id],pre+b2[id]});
	}
	if(v[id].empty())goto aaa;
	sort(v[id].begin(),v[id].end());
	for(auto [x,y,w]:v[id]){
		pre=g[x-1];
		for(i=x;i<=y;i++){
			pre=max(pre,f[1][i]);t1=g[i];
			g[i]=max(g[i],pre+w);
			pre=max(pre,t1);
		}
	}
	aaa:;
}
int main() {
	for(i=0;i<=500000;i++){
		id[i]=it;g[i]=b[i]=b2[i]=b3[i]=-1e18;
		if(!(i%N))it++;
	}
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=3;i++){
		for(j=1;j<=n;j++){
			cin>>f[i][j];
			f[i][j]+=f[i][j-1];
		}
	}
	for(i=1;i<=n;i++){
		f[1][i]-=f[2][i-1];
		b3[id[i]]=max(b3[id[i]],f[1][i]);
	}
	for(i=1;i<=m;i++){
		int l,r,w,x,y;
		cin>>l>>r>>w;
		k=0;
		for(x=1;x<=n;x+=N){
			y=min(x+N-1,n);k++;
			if(y<l||x>r)continue;
			if(l<=x&&y<=r)b2[k]=max(b2[k],0ll-w);
			else v[k].push_back({max(x,l),min(r,y),-w});
		}
		q.push_back({l,r,-w});
	}
	it=1;
	q.push_back({n,n,-1e18});
	sort(q.begin(),q.end());
	for(auto [l,r,w]:q){
		while(it<=id[l]){work((it-1)*N+1,min(it*N,n),it);it++;}
		ll pre=g[l-1];
		for(i=l;i<=r;){
			pre=max({pre,f[1][i],g[i]});
			if(id[i]==id[l]){i++;continue;}
			if(id[i]!=id[r]){
				b[id[i]]=max(b[id[i]],pre+w);
				pre=max(pre,b3[id[i]]);i+=N;
			}
			else g[i]=max(g[i],pre+w),i++;
		}
	}
	for(i=1;i<=n;i++)ans=max(ans,g[i]+f[2][i]+f[3][n]-f[3][i-1]);
	cout<<ans;
}