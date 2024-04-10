#include <bits/stdc++.h>
using namespace std;

unordered_map< int,unordered_map< int,int > > mp;

int i,j,k,n,m,t,u,v,sb[2];
char c;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	while(t--){
		cin>>c;
		if(c=='+'){
			cin>>u>>v>>c;
			if(mp[v][u]){sb[1]++;}
			if(mp[v][u]==c){sb[0]++;}
			mp[u][v]=c;
		}
		if(c=='-'){
			cin>>u>>v;
			if(mp[v][u]){sb[1]--;}
			if(mp[v][u]==mp[u][v]){sb[0]--;}
			mp[u][v]=0;
		}
		if(c=='?'){
			cin>>k;
			cout<<((sb[k%2]>0)?"YES":"NO")<<endl;
		}
	}
}