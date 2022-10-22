#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n;
int p[M],ans[M];
char s[M];
void work(){
	vector<int>a,b;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>p[i];
	cin>>(s+1);
	int t=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			t++;
			a.eb(i);
		}
		else b.eb(i);
	}
	sort(a.begin(),a.end(),[&](const int&l,const int&r){return p[l]<p[r];});
	sort(b.begin(),b.end(),[&](const int&l,const int&r){return p[l]<p[r];});
	for(int i=1;i<=t;++i){
		ans[a[i-1]]=i;
	}
	for(int i=t+1;i<=n;++i){
		ans[b[i-t-1]]=i;
	}
	for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
2
1 2
10
*/