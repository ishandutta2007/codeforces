#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll inf=1e18;

struct edge{
	int w,u,v;
};

bool operator<(const edge&e1,const edge&e2){
	return e1.w<e2.w;
};

vector<int>id;
int getid(int u){return id[u]==u?u:id[u]=getid(id[u]);}

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m,k;cin>>n>>m>>k;
		id.resize(n);
		iota(id.begin(),id.end(),0);
		vector<edge>edges(m);
		for(int i=0;i<m;++i)cin>>edges[i].u>>edges[i].v>>edges[i].w;
		for(int i=0;i<m;++i){--edges[i].u;--edges[i].v;}
		sort(edges.begin(),edges.end());
		vector<edge>tree;
		for(int i=0;i<m;++i)
			if(getid(edges[i].u)!=getid(edges[i].v)){
				id[getid(edges[i].u)]=getid(edges[i].v);
				tree.push_back(edges[i]);
//				cerr<<edges[i].u<<" "<<edges[i].v<<" "<<getid(edges[i].u)<<" "<<getid(edges[i].v)<<endl;
			}
//		cerr<<n<<" "<<tree.size()<<endl;
		assert(tree.size()==n-1);
		ll res=0;
		if(tree.back().w>=k){
			for(int i=n-2;i>=0;--i)
				if(tree[i].w>k)res+=tree[i].w-k;
				else break;
		}
		else{
			ll smaller=-inf,bigger=inf;
			for(int i=0;i<m;++i)
				if(edges[i].w<=k)smaller=max(smaller,ll(edges[i].w));
				else bigger=min(bigger,ll(edges[i].w));
			res=min(k-smaller,bigger-k);
		}
		cout<<res<<endl;
	}
}