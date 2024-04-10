#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,q;
int a[M],id[M];
bool vis[M];
vector<int>s,t;
void work(){
	cin>>n;
	s.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s.eb(a[i]);
	}
	int k=0;
	while(s.size()>1){
		sort(s.begin(),s.end(),[&](const int&l,const int&r){return l>r;});
		while(s.size()&&s.back()==0)s.pop_back(),k++;
		if(s.size()<=1)break;
 		t.clear();
		for(int i=0,S=s.size();i<S-1;++i){
			t.eb(s[i]-s[i+1]);
		}
		if(k){
			t.eb(s.back());
			k--;
		}
		s=t;
	}
	if(s.size()==0)cout<<0<<endl;
	else cout<<s[0]<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
5
0 0 0 8 13

*/