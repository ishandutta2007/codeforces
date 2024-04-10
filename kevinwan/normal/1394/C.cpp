#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
vector<pii>v;
int n;
int xx,yy;
int gv2(int x,int y){
	int ans=-1;
	for(pii p:v){
		if(1LL*(x-p.first)*(y-p.second)>0)ans=max(ans,max(abs(x-p.first),abs(y-p.second)));
		else ans=max(ans,abs(x-p.first)+abs(y-p.second));
	}
	xx=x,yy=y;
	return ans;
}
int gv1(int x){
	if(x<0)return inf;
	int cur=-1;
	if(x==0)cur=0;
	for(int i=1<<18;i;i>>=1){
		if(gv2(x,cur+i)>gv2(x,cur+i+1))cur+=i;
	}
	return gv2(x,cur+1);
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
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int a=0,b=0;
		for(char c:s){
			if(c=='B')a++;
			else b++;
		}
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	n=v.size();
	int cur=-1;
	for(int i=1<<18;i;i>>=1){
		if(gv1(cur+i)>gv1(cur+i+20))cur+=i;
	}
	int ans=inf,besx,besy;
	for(int i=cur+1;i<=cur+20;i++){
		int cand=gv1(i);
		if(cand<ans)besx=xx,besy=yy,ans=cand;
	}
	printf("%d\n",ans);
	for(int i=0;i<besx;i++)printf("B");
	for(int i=0;i<besy;i++)printf("N");
	for(int i=1;i<=100;i++)cerr<<gv1(i)<<endl;
}