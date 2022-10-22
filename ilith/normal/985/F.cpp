#include<bits/stdc++.h>
using namespace std;
long long pw1[200005],pw2[200005];
long long n,m;
long long x,y,len;
char str[200005];
vector<long long>v;
pair<long long,long long>h[26][200005];
pair<long long,long long> get(pair<long long,long long>h[],long long l,long long r){
	pair<long long,long long>tmp=h[r];
	l--;
	if(l>=0){
		tmp.first=(tmp.first-(h[l].first)*pw1[r-l]%998244353+998244353)%998244353;
		tmp.second=(tmp.second-(h[l].second)*pw2[r-l]%998244853+998244853)%998244853;
	}
	return tmp;
}
int main(){
	ios::sync_with_stdio(0);
	pw1[0]=pw2[0]=1;
	for(long long i=1;i<200005;i++){
		pw1[i]=pw1[i-1]*10007%998244353;
		pw2[i]=pw2[i-1]*1919810%998244853;
	}
	cin>>n>>m>>str+1;
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<26;j++){
			h[j][i].first=((h[j][i-1].first)*10007+(1+('a'+j==str[i])))%998244353;
			h[j][i].second=((h[j][i-1].second)*1919810+(1+('a'+j==str[i])))%998244853;
		}
	}
	while(m--){
		cin>>x>>y>>len;
		multiset<pair<long long,long long> >a,b;
		for(long long i=0;i<26;i++){
			a.insert(get(h[i],x,x+len-1));
			b.insert(get(h[i],y,y+len-1));
		}
		puts(a==b?"YES":"NO");
	}
	return 0;
}