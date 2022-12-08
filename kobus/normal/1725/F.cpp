#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define INF INT_MAX
#define pii pair<long long,long long> 
#define f first
#define s second
#define mp make_pair
#define double long double

#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)(s.size())
#define int long long
typedef long long ll;
typedef pair<long long,long long> ii;

#define eps 1e-6
#define MOD 998244353
#define MAXN 512345

#define K 31

pii ranges[512345];
//0 add 1 remove
vector<pii> rf[K];
int ans[K];

void add_in(pii r,int i){
	rf[i].pb(mp(r.f,0));
	rf[i].pb(mp(r.s,1));
}

void add_ranges(pii r,int i){
	int rs=1<<i;
	if(r.s-r.f+1>=rs){
		ans[i]++;
		return;
	}
	r.f%=rs;r.s%=rs;
	if(r.f<=r.s){
		add_in(r,i);
	}
	else{
		add_in(mp(0,r.s),i);
		add_in(mp(r.f,rs-1),i);
	}
}

int32_t main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(2);

	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>ranges[i].f>>ranges[i].s;
	for(int i=0;i<K;i++){
		for(int j=0;j<n;j++){
			add_ranges(ranges[j],i);
		}
	}
	for(int i=0;i<K;i++){
		sort(rf[i].begin(),rf[i].end());
		int val=ans[i];
		for(auto x:rf[i]){
			if(x.s==0)val++;
			else val--;
			ans[i]=max(ans[i],val);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int w;
		cin>>w;
		for(int i=0;i<K;i++){
			if((w>>i)%2){
				//cout<<i<<endl;
				//for(auto x:rf[i])cout<<x.f<<" "<<x.s<<"   ";
				//cout<<endl;
				cout<<ans[i]<<endl;
				break;
			}
		}
	}


	
}