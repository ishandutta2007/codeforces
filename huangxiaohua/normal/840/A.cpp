#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],res[200500];

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	set<pair<int,int> >s2;
	for(i=1;i<=n;i++){
		cin>>k;
		s2.insert({k,i});
	}
	m=n;
	for(auto [i,j]:s2){
		res[j]=a[m--];
	}
	for(i=1;i<=n;i++)cout<<res[i]<<' ';
}