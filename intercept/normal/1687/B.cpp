#include<bits/stdc++.h>
#define eb emplace_back
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n,m;
ll val[M];
int id[M];
string s;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;++i)s.push_back('0');
	for(int i=0;i<m;++i){
		s[i]='1';
		cout<<"? "<<s<<endl;
		cin>>val[i];
		id[i]=i;
		s[i]='0';
	}
	sort(id,id+m,[&](const int&l,const int&r){return val[l]<val[r];});
	ll rex=0;
	for(int i=0;i<m;++i){
		int x=id[i];
		s[x]='1';
		cout<<"? "<<s<<endl;
		ll y;
		cin>>y;
		if(y-rex!=val[x])s[x]='0';
		else rex=y;
	}
	cout<<"! "<<rex<<endl;
	return 0;
}