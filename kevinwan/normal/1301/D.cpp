#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll k;
vector<pair<int,string>>vesh;
void finish(){
	printf("YES\n%d\n",vesh.size());
	for(auto p:vesh)printf("%d %s\n",p.first,p.second.c_str());
	exit(0);
}
void go(string a,int x){
	if(!x)return;
	if(k>a.size()*x){
		k-=a.size()*x;
		vesh.push_back({x,a});
	}
	else{
		if(k/a.size())vesh.push_back({k/a.size(),a});
		if(k%a.size())vesh.push_back({1,a.substr(0,k%a.size())});
		finish();
	}
}
int main(){
	#ifdef LOCAL_PROJECT
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#else
	cin.tie(0);
	cin.sync_with_stdio(0);
	#endif
	int n,m;
	cin>>n>>m>>k;
	if(k>4*n*m-2*n-2*m){printf("NO");return 0;}
	go("R",m-1);
	go("L",m-1);
	for(int i=1;i<n;i++){
		go("D",1);
		go("RUD",m-1);
		go("L",m-1);
	}
	go("U",n-1);
}