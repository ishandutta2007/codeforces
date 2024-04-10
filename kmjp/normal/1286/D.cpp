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

int N;
int X[101010],V[101010],P[101010];
const ll mo=998244353;

struct mat{
	ll p[2][2];
};
mat val[1<<19];

mat mul(mat& L, mat& R) {
	mat V;
	int x,y;
	FOR(x,2) FOR(y,2) V.p[x][y]=(L.p[x][0]*R.p[0][y]+L.p[x][1]*R.p[1][y])%mo;
	return V;
}



ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

bool cmp(vector<int>& L,vector<int>& R) {
	return 1LL*L[0]*R[1]<1LL*R[0]*L[1];
}

vector<vector<int>> cand;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>V[i]>>P[i];
		val[i+(1<<18)].p[0][0]=val[i+(1<<18)].p[0][1]=(100-P[i])*modpow(100)%mo;
		val[i+(1<<18)].p[1][0]=val[i+(1<<18)].p[1][1]=P[i]*modpow(100)%mo;
	}
	for(i=N;i<1<<18;i++) val[i+(1<<18)].p[1][0]=val[i+(1<<18)].p[1][1]=1;
	for(i=(1<<18)-1;i>=1;i--) val[i]=mul(val[2*i],val[2*i+1]);
	
	
	FOR(i,N-1) {
		if(V[i]<V[i+1]) cand.push_back({(X[i+1]-X[i]),V[i+1]-V[i],i,0,0});
		if(V[i]>V[i+1]) cand.push_back({(X[i+1]-X[i]),V[i]-V[i+1],i,1,1});
		cand.push_back({(X[i+1]-X[i]),(V[i]+V[i+1]),i,1,0});
	}
	sort(ALL(cand), cmp);
	ll ret=0;
	ll pre=0;
	FORR(c,cand) {
		ll P=(val[1].p[0][1]+val[1].p[1][1])%mo;
		i=(c[2]+(1<<18));
		val[i].p[c[3]][c[4]]=0;
		while(i>1) {
			i/=2;
			val[i]=mul(val[2*i],val[2*i+1]);
		}
		ll Q=(val[1].p[0][1]+val[1].p[1][1])%mo;
		P=(P-Q+mo)%mo;
		//cout<<P<<" "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<ret<<endl;
		//cout<<"!"<<val[1].p[0][0]<<" "<<val[1].p[0][1]<<" "<<val[1].p[1][0]<<" "<<val[1].p[1][1]<<endl;
		ll tim=c[0]*modpow(c[1])%mo;
		(ret+=P*(tim-pre+mo))%=mo;
		//pre=tim;
	}
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}