#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,res;
vector<tuple<int,int,int>> sb;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>j>>k,sb.push_back({max(j,k),j,k});
	sort(sb.begin(),sb.end());
	for(auto [i,k,j]:sb)if(k>=m)m=max(m,j),res++;
	cout<<res;
}