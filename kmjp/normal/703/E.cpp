#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

int N;
ll K;
ll A[10101];
unordered_map<ll,int> U;
int num[1010][7000];
ll sum[1010][7000];
int from[1010][7000];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(K==1) {
		FOR(i,N) cin>>A[i];
		cout<<1<<endl;
		cout<<1+(min_element(A,A+N)-A)<<endl;
		return;
	}
	
	auto V=enumdiv(K);
	auto VR=V;
	reverse(ALL(VR));
	
	FOR(i,V.size()) U[V[i]]=i, num[0][i]=101010;
	
	num[0][0]=0;
	FOR(x,N) {
		ll X;
		cin>>X;
		
		FOR(i,V.size()) {
			num[x+1][i]=num[x][i];
			sum[x+1][i]=sum[x][i];
			from[x+1][i]=i;
		}
		
		FOR(i,V.size()) if(num[x][i]<1010) {
			ll Z=V[i]*__gcd(X,VR[i]);
			int zi=U[Z];
			if(num[x+1][zi]>num[x][i]+1 || (num[x+1][zi]==num[x][i]+1 && sum[x+1][zi]>sum[x][i]+X)) {
				num[x+1][zi]=num[x][i]+1;
				sum[x+1][zi]=sum[x][i]+X;
				from[x+1][zi]=i;
			}
		}
	}
	x = U.size()-1;
	if(num[N][x]>N) return _P("-1\n");
	vector<int> R;
	for(y=N;y>0;y--) {
		if(from[y][x]!=x) {
			R.push_back(y);
			x=from[y][x];
		}
	}
	_P("%d\n",R.size());
	FORR(r,R) _P("%d ",r);
	_P("\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}