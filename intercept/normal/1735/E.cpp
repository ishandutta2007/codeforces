#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=1009;
int n;
ll a[M],b[M];
vector<ll>l,r;
multiset<ll>s;
bool check(ll d){
	l.clear();
	r.clear();
	s.clear();
	for(int i=1;i<=n;++i)s.insert(b[i]);
	for(int i=n;i>=1;--i){
		auto it=s.find(a[i]+d);
		if(it!=s.end())s.erase(it),r.eb(a[i]);
		else{
			if(a[i]>=d){
				it=s.find(a[i]-d);
				if(it!=s.end())s.erase(it),l.eb(a[i]);
			}
			else{
				it=s.find(d-a[i]);
				if(it!=s.end())s.erase(it),l.eb(a[i]);
			}
		}
		
	}	
	return s.size()==0;
}
void work(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	bool bol=0;
	if(a[n]>b[n]){
		bol=1;
		for(int i=1;i<=n;++i)swap(a[i],b[i]);
	}
	for(int i=n;i>=1;--i){
		if(check(b[n]-a[i])){
			puts("YES");
			for(auto o:l){
				cout<<(int)1e9-o<<" ";
			}
			reverse(r.begin(),r.end());
			for(auto o:r){
				cout<<(int)1e9+o<<" ";
			}
			puts("");
			if(bol){
				cout<<(int)1e9+a[i]-b[n]<<" "<<(int)1e9<<"\n";
			}
			else cout<<(int)1e9<<" "<<(int)1e9+a[i]-b[n]<<"\n";
			return;
		}
		if(a[n]<=b[n]+a[i]&&check(b[n]+a[i])){
			puts("YES");
			for(auto o:l){
				cout<<(int)b[n]+a[i]-o<<" ";
			}
			puts("");
			if(!bol)cout<<(int)b[n]+a[i]<<" "<<0<<"\n";
			else cout<<0<<" "<<(int)b[n]+a[i]<<"\n";
			return;
		}
	}
	puts("NO");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
10
999609239 999619397 999621802 999688421 999774470 999810062 999821773 999857815 999914614 999965809
999648402 999943619 999953777 999788546 999941214 999874595 999705201 999597207 999752954 999741243

YES

999609239 999619397 999621802 999688421 999774470 999810062 999821773 999857815 999914614 999965809 

0 1999563016


*/