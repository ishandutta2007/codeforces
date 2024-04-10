#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res[200500][2],l,r,w,cur;

struct sb{
	int l,r,w,st,id;
	bool operator<(const sb x)const{return l<x.l;}
};

set<int> qu;
vector<struct sb> v[2005000],s;

int main(){
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;k=0;
		qu.clear();
		
		for(i=1;i<=n;i++){
			cin>>l>>r>>w;
			v[l+r-w].push_back({max(0,l-w),l-max(0,w-r),w,l,i});
			qu.insert(l+r-w);
		}
		
		for(auto i:qu){
			sort(v[i].begin(),v[i].end());
			cur=11451419;
			for(auto [l,r,w,st,id]:v[i]){
				if(l>cur){
					k++;
					for(auto [l,r,w,st,id]:s){
						res[id][0]=st-cur;
						res[id][1]=w-res[id][0];
					}
					s.clear();cur=1145141919;
				}
				cur=min(cur,r);
				s.push_back({l,r,w,st,id});
			}
			if(!s.empty())k++;
			for(auto [l,r,w,st,id]:s){
				res[id][0]=st-cur;
				res[id][1]=w-res[id][0];
			}
			s.clear();
		}
		
		cout<<k<<'\n';
		for(i=1;i<=n;i++){
			cout<<res[i][0]<<' '<<res[i][1]<<'\n';
		}
		
		for(auto i:qu){
			v[i].clear();
		}
	}
}