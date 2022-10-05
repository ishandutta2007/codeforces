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


static pair<int,int> const def={0,0};
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,ma; //
	SegTree_3(){
		val.resize(NV*2,def);
		ma.resize(NV*2,def);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return max({val[k],getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1)});
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=max(val[k],v);
			ma[k]=max(ma[k],v);
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max({ma[k],ma[k*2],ma[k*2+1]});
		}
	}
};
SegTree_3<pair<int,int>,1<<20> st;
int lef[303030];

int H,N;
vector<pair<int,int>> S[303030];
pair<int,int> dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>N;
	vector<int> Xs;
	
	FOR(i,N) {
		cin>>j>>x>>y;
		S[j].push_back({x,y+1});
		Xs.push_back(x);
		Xs.push_back(y+1);
	}
	sort(ALL(Xs));
	
	pair<int,int> ma={0,0};
	for(i=1;i<=H;i++) {
		dp[i]={0,0};
		FORR2(a,b,S[i]) {
			a=lower_bound(ALL(Xs),a)-Xs.begin();
			b=lower_bound(ALL(Xs),b)-Xs.begin();
			dp[i]=max(dp[i],st.getval(a,b));
		}
		dp[i].first++;
		pair<int,int> p={dp[i].first,i};
		FORR2(a,b,S[i]) {
			st.update(a,b,p);
		}
		ma=max(ma,make_pair(dp[i].first,i));
	}
	
	x=H;
	int cur=ma.second;
	while(cur) {
		x--;
		lef[cur]=1;
		cur=dp[cur].second;
	}
	
	cout<<x<<endl;
	for(i=1;i<=H;i++) if(lef[i]==0) cout<<i<<" ";
	cout<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}