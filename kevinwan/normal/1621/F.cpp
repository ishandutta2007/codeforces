#include <bits/stdc++.h>
using namespace std;
 
const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=1e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;

ll n,a,b,c;
ll hail(vi czeros,int fones,int tones){
	ll pos=0,ex=0,cans=0,ans=0;
	while(true){
		while(pos!=czeros.size()&&czeros[pos]==1){
			pos++;
			ex++;
		}
		if(pos!=czeros.size()){
			ans=max(ans,cans+a);
		}
		if(fones&&pos!=czeros.size()){
			cans+=a;
			czeros[pos]--;
		}
		else{
			if(ex==0)break;
			cans-=c;
			ex--;
			if(fones<tones-1)fones++;
		}
		ans=max(ans,cans);
		if(fones==0)break;
		cans+=b;
		fones--,tones--;
		ans=max(ans,cans);
	}
	return ans;
}

void solve(){
	cin>>n>>a>>b>>c;
	string s;
	cin>>s;
	vi zeros;
	int fones=0, tones=0;
	int num=1;
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1])num++;
		else{
			if(s[i]=='1')zeros.push_back(num);
			else fones+=num-1,tones+=num;
			num=1;
		}
	}
	if(s[n-1]=='0')zeros.push_back(num);
	else fones+=num-1,tones+=num;
	
	if(false){
		int fzeros=0;
		for(int x:zeros)fzeros+=num-1;
		if(fzeros>fones)printf("%lld\n",fones*b+(fones+1)*a);
		else if(fzeros==fones)printf("%lld\n",fones*b+fzeros*a);
		else printf("%lld\n",fzeros*a+(fzeros+1)*b);
		return;
	}

	vi spec;
	if(s[0]=='0'){
		spec.push_back(zeros[0]);
		zeros.erase(zeros.begin());
	}
	if(s[n-1]=='0'&&zeros.size()){
		spec.push_back(zeros.back());
		zeros.pop_back();
	}
	//cerr<<zeros.size()<<endl;
	sort(zeros.begin(),zeros.end());
	for(int x:spec)zeros.push_back(x);
	ll ans=0;
	ans=max(ans,hail(zeros,fones,tones));
	if(fones){
		fones--;
		tones--;
		ans=max(ans,hail(zeros,fones,tones)+b);
	}
	printf("%lld\n",ans);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin >> tc;
	while(tc--){
		solve();
	}
}