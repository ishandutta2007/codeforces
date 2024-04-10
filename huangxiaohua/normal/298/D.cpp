#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500],c[200500],it,p1[200500],p2[200500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		c[++it]=a[i];
	}
	for(i=1;i<=m;i++){
		cin>>b[i];
		c[++it]=b[i];
	}
	sort(c+1,c+it+1);
	it=unique(c+1,c+it+1)-c-1;
	for(i=1;i<=n;i++){
		p1[lower_bound(c+1,c+it+1,a[i])-c]++;
	}
	for(i=1;i<=m;i++){
		p2[lower_bound(c+1,c+it+1,b[i])-c]++;
	}
	for(i=it;i>=1;i--){
		p1[i]+=p1[i+1];
		p2[i]+=p2[i+1];
		if(p1[i]>p2[i]){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}