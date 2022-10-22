#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e5+9;
int n;
ll ans,a[M];
int id[M];
int bit[M];
void add(int x,int v){
	for(;x<=n;x+=x&-x)bit[x]+=v;
}
int ask(int x,int rex=0){
	for(;x;x-=x&-x)rex+=bit[x];
	return rex;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],a[i]+=a[i-1],id[i]=i;
	for(int i=1;i<=n;++i){
		if(a[i]<0||a[i]>a[n]){
			puts("-1");
			return 0;
		}
	}
	sort(id+1,id+n+1,[&](const int&l,const int&r){return a[l]==a[r]?l>r:a[l]>a[r];});
	for(int i=1;i<=n;++i){
		int x=id[i];
		ans+=ask(x);
		add(x,1);
	}
	cout<<ans<<"\n";
	return 0;
}