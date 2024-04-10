#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,q;
int a[M],p[1009],tot;
vector<ll>v[M];
multiset<ll>s;
void change(int o,int i,int x){
	s.erase(s.find(v[o][i%o]*o));
	v[o][i%o]+=x;
	s.insert(v[o][i%o]*o);
}
ll get(){
	return (*s.rbegin());
}
void work(){
	tot=0;
	cin>>n>>q;
	s.clear();
	int m=n;
	for(int i=2;i<=m;++i){
		v[n/i].clear();
		if(m%i==0){
			while(m%i==0)m/=i;
			p[++tot]=n/i;
			v[n/i].resize(n/i);
		}
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=1;j<=tot;++j){
			int o=p[j];
			v[o][i%o]+=a[i];
		}
	}
	for(int j=1;j<=tot;++j){
		int o=p[j];
		for(auto x:v[o])s.insert(x*o);
	}
	cout<<get()<<"\n";
	for(int i=1;i<=q;++i){
		int id,x;
		cin>>id>>x;
		for(int j=1;j<=tot;++j){
			int o=p[j];change(o,id,x-a[id]);
		}
		a[id]=x;
		cout<<get()<<"\n";
	}
}
int main(){
	cin.tie(NULL)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
4 4
4 1 3 2
2 6
4 6
1 1
3 11
*/