#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod = 1e9+7;
const int mn = 3e5+10;
const double eps = 1e-8;

int bit[mn],tr[mn];
void upd(int a,int b){for(tr[a]+=b;a<mn;a+=a&-a)bit[a]+=b;}
int qu(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int rqu(int b){
	int cur=0,sum=0;
	for(int i=1<<17;i;i>>=1){
		if(sum+bit[cur+i]<b)sum+=bit[cur+=i];
	}
	return cur+1;
}
deque<int> p[26];
void solve(){
	int n;
	string s,t;
	cin>>n>>s>>t;
	s=" "+s;
	t=" "+t;
	for(int i=1;i<=n;i++)upd(i,1);
	for(int i=0;i<26;i++)p[i].clear();
	for(int i=1;i<=n;i++)p[s[i]-'a'].push_back(i);
	ll ans=LLONG_MAX,cur=0;
	for(int i=1;i<=n;i++){
		int ri=rqu(i);
		char c = s[ri];
		if(c<t[i]){
			ans=min(ans,cur);
			break;
		}
		//go for <
		int bes=-1,pos=n+1;
		for(int d=0;d<int(t[i])-'a';d++){
			if(p[d].size()&&p[d].front()<pos)bes=d,pos=p[d].front();
		}
		if(bes!=-1){
			int mv=qu(pos)-i;
			ans=min(ans,cur+mv);
		}
		//continue with =
		int d=t[i]-'a';
		if(p[d].empty())break;
		pos = p[d].front();
		//cerr<<pos<<endl;
		p[d].pop_front();
		int mv = qu(pos)-i;
		cur+=mv;
		upd(ri,1);
		upd(pos,-1);
	}
	if(ans==LLONG_MAX)ans=-1;
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)upd(i,-tr[i]),tr[i]=0;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}