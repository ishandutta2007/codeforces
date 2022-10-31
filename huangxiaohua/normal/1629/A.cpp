#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[66666];

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		multiset<pair<int,int> >s;
		for(k=1;k<=n;k++)cin>>a[k];
		for(k=1;k<=n;k++){cin>>j;s.insert({a[k],j});}
		for(auto [i,j]:s){
			if(m>=i)m+=j;
		}
		cout<<m<<endl;
	}
}