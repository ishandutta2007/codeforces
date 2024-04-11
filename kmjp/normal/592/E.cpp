#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,C,D;
vector<pair<ll,ll>> V;
ll num[456789],num2[456789];
ll S[456789];
ll ret;
int same[456789];

bool comp(pair<ll,ll> &L,pair<ll,ll> &R) {
	if(L==R) return 0;
	if(L.second==0 && L.first>0) return 1;
	if(R.second==0 && R.first>0) return 0;
	if(L.second>0 && R.second<=0) return 1;
	if(R.second>0 && L.second<=0) return 0;
	if(L.second>=0 && R.second<0) return 1;
	if(R.second>=0 && L.second<0) return 0;
	return L.first*R.second-L.second*R.first>0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C>>D;
	
	FOR(i,N) {
		cin>>x>>y;
		x-=C;
		y-=D;
		int g=__gcd(abs(x),abs(y));
		V.push_back({x/g,y/g});
	}
	
	sort(ALL(V),comp);
	FOR(i,N) {
		num[i]=max(i+1LL,(i)?num[i-1]:0);
		if(V[i].second<0 || (V[i].second==0&&V[i].first<0)) num[i]=N;
		else {
			pair<ll,ll> rev={-V[i].first,-V[i].second};
			while(num[i]<N && comp(V[num[i]],rev)) num[i]++;
		}
		num2[i]=max(num[i],(i)?num2[i-1]:0);
		while(num2[i]<N && V[num2[i]].first==-V[i].first && V[num2[i]].second==-V[i].second) num2[i]++;
		
		S[i]=((i)?S[i-1]:0)+num[i];
	}
	for(i=N-1;i>=0;i--) {
		if(i<N-1&&V[i]==V[i+1]) same[i]=same[i+1];
		else same[i]=i;
	}
	
	FOR(x,N) ret+=(S[num[x]-1]-S[same[x]])-num2[same[x]]*(num[same[x]]-1-same[x]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}