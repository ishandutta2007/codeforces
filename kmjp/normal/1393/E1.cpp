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

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;


int N;
string S[101010];
deque<int> Q[101010];
vector<ll> dp[101010];
RollingHash rh[101010];

const ll mo=1000000007;

pair<ll,ll> gethash(int i,int p,int len) {
	if(len<=p) {
		return rh[i].hash(0,len-1);
	}
	pair<ll,ll> L=rh[i].hash(0,p-1);
	pair<ll,ll> R=rh[i].hash(p+1,len);
	return rh[i].concat(L,R,len-p);
}

int comp(int i,int p,int j,int q) {
	int a=(int)S[i].size()-(p<S[i].size());
	int b=(int)S[j].size()-(q<S[j].size());
	int ml=min(a,b);
	int cur=0;
	int x;
	for(x=20;x>=0;x--) if(cur+(1<<x)<=ml) {
		auto L=gethash(i,p,cur+(1<<x));
		auto R=gethash(j,q,cur+(1<<x));
		if(L==R) cur+=1<<x;
	}
	
	if(cur==ml) {
		return a<=b;
	}
	else {
		char c=S[i][cur+(cur>=p)];
		char d=S[j][cur+(cur>=q)];
		return c<=d;
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	Q[0].push_back(0);
	dp[0].push_back(1);
	rh[0].init(S[0]);
	
	FOR(i,N) {
		cin>>S[i+1];
		rh[i+1].init(S[i+1]);
		dp[i+1].resize(S[i+1].size()+1);
		
		vector<vector<int>> cand;
		j=0;
		while(j<S[i+1].size()) {
			cand.push_back({0,j,1});
			x=j+1;
			while(x<S[i+1].size()&&S[i+1][j]==S[i+1][x]) x++, cand.back()[2]++;
			if(x==S[i+1].size()||S[i+1][j]>S[i+1][x]) cand.back()[0]=1;
			j=x;
		}
		
		
		reverse(ALL(cand));
		Q[i+1].push_back(S[i+1].size());
		FORR(c,cand) {
			if(c[0]) {
				FOR(j,c[2]) Q[i+1].push_front(c[1]+j);
			}
			else {
				FOR(j,c[2]) Q[i+1].push_back(c[1]+j);
			}
		}
		int p=0,q;
		ll sum=0;
		FOR(q,Q[i+1].size()) {
			while(p<Q[i].size() && comp(i,Q[i][p],i+1,Q[i+1][q])) (sum+=dp[i][p++])%=mo;
			//cout<<q<<" "<<S[i+1].substr(0,Q[i+1][q])<<S[i+1].substr(Q[i+1][q]+1)<<" "<<p<<" "<<sum<<endl;
			dp[i+1][q]=sum;
		}
	}
	ll sum=0;
	FORR(d,dp[N]) sum+=d;
	cout<<sum%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}