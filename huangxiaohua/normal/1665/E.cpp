#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[100500];
vector<int> v;

struct SB{
	#define md ((l+r)>>1)
	#define ls (id*2)
	#define rs (ls+1)
	
	vector<int> f[400500];
	
	vector<int> hb(vector<int> &f1,vector<int> &f2){
		auto i1=f1.begin(),i2=f2.begin();
		vector<int> ans;
		while(i1!=f1.end()||i2!=f2.end()){
			if(i1==f1.end()){
				ans.push_back(*i2);
				i2++;
			}
			else if(i2==f2.end()){
				ans.push_back(*i1);
				i1++;
			}
			else if(*i1<*i2){
				ans.push_back(*i1);
				i1++;
			}
			else{
				ans.push_back(*i2);
				i2++;
			}
			if(ans.size()>40)break;
		}
		return ans;
	}
	
	void build(int id,int l,int r){
		if(l==r){
			f[id]={a[l]};
			return;
		}
		build(ls,l,md);build(rs,md+1,r);
		f[id]=hb(f[ls],f[rs]);
	}
	
	void get(int id,int l,int r,int x,int y){
		if(x<=l&&r<=y){
			v=hb(v,f[id]);return;
		}
		if(x<=md)get(ls,l,md,x,y);
		if(y>md)get(rs,md+1,r,x,y);
	}
}sb;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sb.build(1,1,n);
		cin>>m;
		while(m--){
			int l,r,sz,res=2e9;
			cin>>l>>r;
			v.clear();
			sb.get(1,1,n,l,r);
			sz=v.size();
			for(i=0;i<sz;i++)for(j=i+1;j<sz;j++){
				res=min(res,v[i]|v[j]);
			}
			cout<<res<<'\n';
		}
	}
}