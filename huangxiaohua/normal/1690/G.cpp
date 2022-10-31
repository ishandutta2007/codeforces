#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,lst,st,ed,cur[100500];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		set<tuple<int,int,int> >s;
		for(i=1;i<=n;i++){
			cin>>k;
			cur[i]=k;
			if(i==1){
				lst=k;st=i;continue;
			}
			if(k<lst){
				if(lst>=0){
					s.insert({st,i-1,lst});
				}
				lst=k;st=i;
			}
		}
		s.insert({st,n,lst});

		while(m--){
			int x,y;
			cin>>x>>y;
			//printf("NMSL\n");
			cur[x]-=y;
			auto [l,r,v]=*--s.upper_bound({x,1e9,1e9});
			if(v<=cur[x]){
				cout<<s.size()<<' ';continue;
			}
			s.erase({l,r,v});ed=r;
			if(l!=x)s.insert({l,x-1,v});
			v=cur[x];
			while(1){
				auto it=s.upper_bound({x,1e9,1e9});
				if(it==s.end())break;
				auto [l1,r1,v1]=*it;
				if(v1<v)break;
				s.erase({l1,r1,v1});
				ed=r1;
			}
			s.insert({x,ed,v});
			cout<<s.size()<<' ';
			//for(auto [l,r,v]:s)printf("a%d %d %d\n",l,r,v);
		}
		cout<<'\n';
	}
}