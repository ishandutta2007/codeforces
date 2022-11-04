#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define xx first
#define yy second
#define sz(x) (int)(x).size()
#define gc getchar
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

ll l, r, k;
vector<vector<int>> res;
vector<int> akt;
void gen(int x, int cnt) {
	if(cnt>k) {
		return ;
	}
	if(x==10) {
		res.push_back(akt);
		return ;
	}
	
	gen(x+1, cnt);
	akt.push_back(x);
	gen(x+1, cnt+1);
	akt.pop_back();
}

const ll mod=998244353;

ll fpow(ll a, ll b) {
	if(b==0) return 1;
	ll fele=fpow(a, b/2);
	ll ans=(fele*fele)%mod;
	if(b&1) ans=(ans*a)%mod;
	return ans;
}

pair<ll,ll> dp[20][2][2][1024];
bool setted[20][2][2][1024];

void init() {
	memset(setted, 0, sizeof setted);
}
vector<int> conv(string t) {
	vector<int> x;
	for(auto i:t) {
		x.push_back(i-'0');
	}
	
	return x;
}
//szumma, lehetsgek
vector<int> szam_l, szam_r;
vector<int> H;
pair<ll, ll> calc(int x, bool kisebb, bool nagyobb, int volt) {
	if(setted[x][kisebb][nagyobb][volt]) {
		return dp[x][kisebb][nagyobb][volt];
	}
			//cerr<<x<<" "<<kisebb<<" "<<nagyobb<<" "<<volt<<"\n";

	if(x==(int)szam_l.size()) {
		bool ok=true;
		int cnt=0;
		for(int i=0;i<H.size();++i) {
			cnt+=(volt&(1<<i))!=0;
		}
		ok&=cnt<=k;
		//cerr<<ok<<"ok\n";
		if(ok)
		return {0, 1};
		else 
		return {0,0};
	}
	
	ll sum=0, ans=0;
	ll jegyek=fpow(10, szam_r.size()-x-1);
	
	if(kisebb && nagyobb) {
		int ind=-1;
		for(auto i:H) {
			ind++;
			pair<ll, ll> akt=calc(x+1, true, true, volt|(1<<ind));

			sum+=(((jegyek*i)%mod)*(akt.second)%mod+akt.first)%mod;
			ans+=akt.second;
			ans%=mod;
		}
	}else {
		int ind=-1;
		for(auto i:H) {
			ind++;
			if(!kisebb && szam_r[x]<i) continue ; 
			if(!nagyobb && szam_l[x]>i) continue ; 
			
			pair<ll, ll> akt=calc(x+1, kisebb|(szam_r[x]>i), nagyobb|(szam_l[x]<i), volt|(1<<ind));
			
			sum+=(((jegyek*i)%mod)*(akt.second)%mod+akt.first)%mod;
			ans+=akt.second;
			ans%=mod;
		}
	}
		//cerr<<x<<" "<<kisebb<<" "<<nagyobb<<" "<<volt<<": "<<sum<<"-"<<ans<<"\n";

	setted[x][kisebb][nagyobb][volt]=true;
	return dp[x][kisebb][nagyobb][volt]={sum, ans};
	/*if(kisebb) {
		pair<ll, ll> akt=calc(x+1, szam, H, true);
		ll jegyek=fpow(10, szam.size()-x-1);
		ll sum=0, ans=0;
		for(auto i:H) {
			sum+=((jegyek*i)%mod)*(akt.second%mod)%mod;
			sum%=mod;
			ans+=akt.second;
		}
	}*/
}

int main() {
	IO;
	
	cin>>l>>r>>k;
	
	string L,R;
	L=to_string(l);
	R=to_string(r);
	
	gen(0,0);
	szam_l=conv(L); szam_r=conv(R);
	for(int i=0;i<10;++i) H.push_back(i);
	if(szam_l.size()==szam_r.size()) {
		ll sum=0;
		init();

			init();
			//for(auto j:i) cerr<<j<<" ";
			//cerr<<"|";
			//cerr<<calc(0,szam_l, szam_r, i, false, false, 0).xx<<" ";
			//cerr<<calc(0,szam_l, szam_r, i, false, false, 0).yy<<"\n";
			//cerr<<";\n";
			sum=(sum+calc(0,false, false, 0).xx)%mod;
		
		cout<<sum<<"\n";
	}else {
		ll akt=1;
		vector<ll> lst;
		lst.push_back(l);
		lst.push_back(r);
		
		for(int i=0;i<=18;++i) {
			if(akt>l && akt<r) lst.push_back(akt);
			if(akt-1>l && akt-1<r) lst.push_back(akt-1);
			akt*=10;
		}

		sort(lst.begin(), lst.end());
		
		ll sum=0;
		for(int i=0;i+1<lst.size();i++) {
			string x=to_string(lst[i]);
			string y;
			if(lst[i+1]!=r) {
				y=to_string(lst[i+1]-1);
			}else {
				y=to_string(lst[i+1]);
			}
			//cerr<<x<<" "<<y<<"\n";
			//assert(x.size()==y.size());
			
				init();
				szam_l=conv(x);
				szam_r=conv(y);
				sum=(sum+calc(0, false, false, 0).xx)%mod;

		}
		
		cout<<sum<<"\n";
	}
	return 0;
}