#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,g[300500],f[300500],sb[300500];
vector<int> v[300500];
queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j;
		k=__gcd(j,k);
		f[j]++;
		if(!g[j]){g[j]=1;q.push(j);}
	}
	for(i=1;i<=300000;i++){
		v[i].push_back(i);
		for(j=i+i;j<=300000;j+=i)v[j].push_back(i),f[i]+=f[j];
		reverse(v[i].begin(),v[i].end());
	}
	if(k!=1){cout<<-1;return 0;}
	while(!q.empty()){
		k=q.front();q.pop();
		m=v[k].size();
		for(auto i:v[k]){
			sb[i]=f[i];
			for(auto j:v[k]){
				if(j==i)break;
				if(!(j%i))sb[i]-=sb[j];
			}
			if(sb[i]&&!g[i]){
				g[i]=g[k]+1;
				q.push(i);
			}
		}
	}
	cout<<g[1];
}