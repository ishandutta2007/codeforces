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


int N;
string S[3];
int p[7];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

unordered_map<ll,pair<int,int>> memo;
UF<12> uf;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		ll m=(1LL*l.first<<32)+r.first;
		if(memo.count(m)) {
			auto p=memo[m];
			p.second=l.second+r.second-p.second;
			return p;
		}
		
		int Lmask=l.first%64;
		int decL=l.first/64;
		
		int Rmask=r.first%64;
		int decR=r.first/64;
		uf.reinit();
		int num=l.second+r.second;
		int i,j;
		FOR(i,6) {
			j=decL/p[i]%6;
			uf(i,j);
			j=decR/p[i]%6;
			uf(i+6,j+6);
		}
		FOR(i,3) {
			if((Lmask&(1<<(i+3)))&&(Rmask&(1<<(i)))) {
				if(uf[i+3]!=uf[i+6]) {
					num--;
					uf(i+3,i+6);
				}
			}
		}
		int tar[12]={};
		FOR(i,3) {
			tar[uf[i]]=i;
			tar[uf[i+9]]=i+3;
		}
		
		int mask=(Lmask%8)+(Rmask/8)*8;
		int dec=0;
		FOR(i,3) {
			dec+=tar[uf[i]]*p[i];
			dec+=tar[uf[i+9]]*p[i+3];
		}
		memo[m]={dec*64+mask, l.second+r.second-num};
		return {dec*64+mask, num};
	};
	
	SegTree_1(){val=vector<V>(NV*2);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
};
SegTree_1<pair<int,int>,1<<19> st;
char buf[502020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p[0]=1;
	FOR(i,6) p[i+1]=p[i]*6;
	
	scanf("%d",&N);
	FOR(y,3) {
		scanf("%s",buf);
		S[y]=buf;
	}
	FOR(i,N) {
		x=(S[0][i]=='1')*4+(S[1][i]=='1')*2+(S[2][i]=='1');
		
		if(x==5) {
			y=0;
			FOR(j,6) y+=(j%3)*p[j];
			st.val[i+(1<<19)]={y*64+x*8+x,2};
		}
		else if(x) {
			st.val[i+(1<<19)]={x*8+x,1};
		}
	}
	for(i=(1<<19)-1;i>=1;i--) st.val[i]=st.comp(st.val[2*i],st.val[2*i+1]);
	
	int Q;
	scanf("%d",&Q);
	while(Q--) {
		int L,R;
		scanf("%d%d",&L,&R);
		L--;
		auto a=st.getval(L,R);
		_P("%d\n",a.second);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}