#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n;
int len(int x){
	int l=0;
	while(x){
		x/=10;
		l++;
	}
	return l;
}
multiset<int>s,t;
int a[M],b[M];
void work(){
	s.clear();
	t.clear();
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s.insert(a[i]);
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		auto it=s.find(b[i]);
		if(it!=s.end()){
			s.erase(it);
		}
		else t.insert(b[i]);
	}
	vector<int>c;
	for(auto o:s){
		if(o>9){
			c.eb(o);
			ans++;
		}
	}
	for(auto o:c){
		s.erase(o);
		s.insert(len(o));
	}
	c.clear();
	for(auto o:t){
		if(o>9){
			c.eb(o);
			ans++;
		}
	}
	for(auto o:c){
		t.erase(o);
		t.insert(len(o));
	}
	for(auto o:t){
		auto it=s.find(o);
		if(it!=s.end()){
			s.erase(it);
		}
		else if(o>1)ans++;
	}
	for(auto o:s){
		if(o>1)ans++;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
4 1
3 4 0


*/