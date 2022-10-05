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
string A;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bt;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<char,int> to;
	to['A']=0;
	to['N']=1;
	to['T']=2;
	to['O']=3;
	string C="ANTO";
	
	cin>>T;
	while(T--) {
		cin>>A;
		N=A.size();
		int cnt[4]={};
		ll num=-1;
		string ret;
		FOR(i,N) {
			cnt[to[A[i]]]++;
		}
		vector<int> V={0,1,2,3};
		do {
			deque<int> Q[4];
			FOR(i,N) {
				Q[to[A[i]]].push_back(i);
				bt.add(i,1);
			}
			string tmp;
			FORR(v,V) {
				FOR(i,cnt[v]) tmp+=C[v];
			}
			ll sum=0;
			FORR(c,tmp) {
				x=Q[to[c]][0];
				sum+=bt(x);
				bt.add(x,-1);
				Q[to[c]].pop_front();
			}
			if(sum>num) ret=tmp, num=sum;
			
			
		} while(next_permutation(ALL(V)));
		
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}