#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		set<pair<int,int> >s;
		for(i=1;i<=n;i++){
			cin>>k;
			s.insert({k,i});
		}
		cout<<((*s.begin()).second)<<' '<<((*--s.end()).second)<<'\n';
	}
}