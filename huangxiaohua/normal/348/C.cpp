#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,id[666],it,a[100500],num[100500],sb;
ll f[100500],w;
string ch;
vector<int> v[100500];
struct sb{
	int id,a[355];
	ll w,d;
	vector<int> v;
}s[100500];

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>t;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=m;i++){
		cin>>k;
		if(k>=333){
			id[++it]=i;
			s[i].id=it;
		}
		while(k--){
			cin>>j;
			s[i].w+=a[j];s[i].v.push_back(j);
			if(s[i].id){
				v[j].push_back(it);
			}
		}
	}
	for(i=1;i<=it;i++){
		for(auto j:s[id[i]].v){num[j]++;}
		for(j=1;j<=it;j++){
			for(auto k:s[id[j]].v){s[id[i]].a[j]+=num[k];}
		}
		for(auto j:s[id[i]].v){num[j]--;}
	}
	for(i=1;i<=m;i++){
		if(s[i].id){continue;}
		for(auto j:s[i].v){
			for(auto k:v[j]){
				s[i].a[k]++;
			}
		}
	}
	while(t--){
		cin>>ch>>sb;
		if(ch=="+"){
			cin>>w;
			s[sb].d+=w;
			for(i=1;i<=it;i++){
				s[id[i]].w+=w*s[sb].a[i];
			}
			if(!s[sb].id){
				for(auto i:s[sb].v){
					f[i]+=w;
				}
			}
		}
		else{
			if(s[sb].id){
				cout<<s[sb].w<<'\n';
			}
			else{
				ll res=s[sb].w;
				for(i=1;i<=it;i++){
					res+=s[id[i]].d*s[sb].a[i];
				}
				for(auto i:s[sb].v){
					res+=f[i];
				}
				cout<<res<<'\n';
			}
		}
	}
}