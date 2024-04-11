#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N;
ll A[101010];
const ll mo=998244353;
ll S[101010];
map<ll,pair<int,int>> R;

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		R.clear();
		FOR(i,N) {
			cin>>A[i];
		}
		R[0]={0,0};
		set<ll> V;
		V.insert(0);
		FOR(i,N) {
			S[i+1]=S[i]+A[i];
			V.insert(-S[i+1]);
			if(R.count(S[i+1])) {
				R[S[i+1]].second=i+1;
			}
			else {
				R[S[i+1]]={i+1,i+1};
			}
		}
		ll ppat=0,sum=0;
		FORR(v,V) {
			ll a=-v;
			if(2*a>S[N]) continue;
			ppat=0;
			if(2*a==S[N]) {
				auto p=R[a];
				int num=p.second-p.first+1;
				if(a==0) {
					for(i=0;i<=num-2;i++) ppat+=comb(num-2,i);
				}
				else {
					for(i=1;i<=num;i++) ppat+=comb(num,i);
				}
				
			}
			else if(V.count(-(S[N]-a))) {
				auto p=R[a];
				auto q=R[S[N]-a];
				int x=p.second-p.first+1;
				int y=q.second-q.first+1;
				
				if(a==0) {
					for(i=0;i<=min(x-1,y-1);i++) {
						(ppat+=comb(x-1,i)*comb(y-1,i))%=mo;
					}
				}
				else {
					for(i=1;i<=min(x,y);i++) {
						(ppat+=comb(x,i)*comb(y,i))%=mo;
					}
				}
				ppat=ppat*(sum+1)%mo;
			}
			ppat%=mo;
			(sum+=ppat)%=mo;
		}
		
		
		
		cout<<ppat<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}