#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000],x,y,pos[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=0){
				pos[++m]=i;
			}
		}
		if(m&1){
			cout<<"-1\n";continue;
		}
		if(!m){
			cout<<1<<'\n'<<1<<' '<<n<<'\n';continue;
		}
		set<pair<int,int> >s;
		for(i=1;i<=m;i+=2){
			if(a[pos[i]]!=a[pos[i+1]]){
				if(pos[i-1]+1<=pos[i]-1)s.insert({pos[i-1]+1,pos[i]-1});
				s.insert({pos[i],pos[i]});
				if(pos[i]+1!=pos[i+1])s.insert({pos[i]+1,pos[i+1]-1});
				s.insert({pos[i+1],pos[i+1]});
			}
			else{
				if(pos[i]+1==pos[i+1]){
					if(pos[i-1]+1<=pos[i]-1)s.insert({pos[i-1]+1,pos[i]-1});
					s.insert({pos[i],pos[i+1]});
				}
				else{
					if(pos[i-1]+1<=pos[i]-1)s.insert({pos[i-1]+1,pos[i]-1});
					s.insert({pos[i],pos[i+1]-2});
					s.insert({pos[i+1]-1,pos[i+1]});
				}
			}
		}
		if(pos[m]!=n)s.insert({pos[m]+1,n});
		cout<<s.size()<<'\n';
		for(auto [i,j]:s)cout<<i<<' '<<j<<'\n';
	}
}