#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=2e5+9;
int n;
char s[M],t[M];
void work(){
	cin>>n>>s+1>>t+1;
	vector<pii>a,b;
	if(s[1]!=t[1]||s[n]!=t[n]){
		puts("-1");
		return;
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='1'&&(i==1||s[i-1]!='1')){
			int r=i;
			while(r+1<=n&&s[r+1]=='1')r++;
			a.eb(i,r);
		}
	}
	for(int i=1;i<=n;++i){
		if(t[i]=='1'&&(i==1||t[i-1]!='1')){
			int r=i;
			while(r+1<=n&&t[r+1]=='1')r++;
			b.eb(i,r);
		}
	}
	if(a.size()!=b.size())puts("-1");
	else{
		ll ans=0;
		for(int i=0;i<a.size();++i){
			ans+=abs(a[i].fi-b[i].fi)+abs(a[i].se-b[i].se);
		}
		cout<<ans<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
4 3 2
mark
1 4
5 7
3 8
1
10
*/