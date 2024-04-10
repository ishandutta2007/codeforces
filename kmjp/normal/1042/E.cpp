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

int H,W;
int A[1010][1010];
int R,C;
map<int,vector<pair<int,int>>> M;
ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	
	cin>>R>>C;
	R--,C--;
	M[A[R][C]].push_back({C,R});
	FOR(y,H) FOR(x,W) if(A[y][x]<A[R][C]) M[A[y][x]].push_back({x,y});
	
	
	ll ret=0;
	int sum=0;
	ll P=1;
	int num=0;
	ll X2=C*C,Y2=R*R,X=C,Y=R;
	vector<vector<pair<int,int>>> step;
	FORR(m,M) if(m.first<A[R][C]) num+=m.second.size(), step.push_back(m.second);
	reverse(ALL(step));
	
	FORR(s,step) {
		FORR(v,s) {
			(ret+=((v.first*v.first+v.second*v.second+X2+Y2-2*v.first*X-2*v.second*Y)%mo+mo)%mo*modpow(num))%=mo;
		}
		X2=X2*(num-s.size())%mo;
		Y2=Y2*(num-s.size())%mo;
		X=X*(num-s.size())%mo;
		Y=Y*(num-s.size())%mo;
		FORR(v,s) {
			X2+=v.first*v.first;
			Y2+=v.second*v.second;
			X+=v.first;
			Y+=v.second;
		}
		X2=X2*modpow(num)%mo;
		Y2=Y2*modpow(num)%mo;
		X=X*modpow(num)%mo;
		Y=Y*modpow(num)%mo;
		num-=s.size();
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}