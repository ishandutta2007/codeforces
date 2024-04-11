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
int DY[202020][2],DX[202020][2];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	SegTree_3(){
		val.resize(NV*2,{-1LL,0LL,0LL,0LL});
	};
	V merge(V a,V b,int s) {
		V c={1LL<<60,1LL<<60,1LL<<60,1LL<<60};
		int w,x,y,z;
		FOR(w,2) FOR(x,2) FOR(y,2) FOR(z,2) {
			int sx,sy,tx,ty;
			if(x==0) sy=s,sx=DX[s-1][0];
			if(x==1) sx=s,sy=DY[s-1][1];
			if(y==0) ty=s,tx=DX[s][0];
			if(y==1) tx=s,ty=DY[s][1];
			c[w+z*2]=min(c[w+z*2],a[w+x*2]+b[y+z*2]+abs(sy-ty)+abs(sx-tx));
			
		}
		return c;
	}
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return {-1LL,0LL,0LL,0LL};
		if(x<=l && r<=y) {
			if(val[k][0]==-1) {
				auto a=getval(x,y,l,(l+r)/2,k*2);
				auto b=getval(x,y,(l+r)/2,r,k*2+1);
				if(a[0]==-1) val[k]=b;
				else if(b[0]==-1) val[k]=a;
				else val[k]=merge(a,b,(l+r)/2);
			}
			return val[k];
		}
		auto a=getval(x,y,l,(l+r)/2,k*2);
		auto b=getval(x,y,(l+r)/2,r,k*2+1);
		if(a[0]==-1) return b;
		if(b[0]==-1) return a;
		return merge(a,b,(l+r)/2);
	}
};
SegTree_3<array<ll,4>,1<<20> st;

int M,X1,X2,Y1,Y2;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N-1;i++) {
		cin>>DY[i][0]>>DX[i][0]>>DY[i][1]>>DX[i][1];
		st.val[(1<<20)+i]={0,1LL<<30,1LL<<30,0};
	}
	
	
	cin>>M;
	while(M--) {
		cin>>Y1>>X1>>Y2>>X2;
		if(max(Y1,X1)>max(Y2,X2)) {
			swap(Y1,Y2);
			swap(X1,X2);
		}
		if(max(Y1,X1)==max(Y2,X2)) {
			cout<<abs(Y2-Y1)+abs(X2-X1)<<endl;
		}
		else {
			int ss=max(X1,Y1);
			int ts=max(X2,Y2);
			auto V=st.getval(ss,ts);
			ll ret=1LL<<60;
			ret=min(ret,abs(Y1-DY[ss][0])+abs(X1-DX[ss][0])+V[0]+abs(Y2-(DY[ts-1][0]+1))+abs(X2-DX[ts-1][0])+ts-ss);
			ret=min(ret,abs(Y1-DY[ss][1])+abs(X1-DX[ss][1])+V[1]+abs(Y2-(DY[ts-1][0]+1))+abs(X2-DX[ts-1][0])+ts-ss);
			ret=min(ret,abs(Y1-DY[ss][0])+abs(X1-DX[ss][0])+V[2]+abs(Y2-DY[ts-1][1])+abs(X2-(DX[ts-1][1]+1))+ts-ss);
			ret=min(ret,abs(Y1-DY[ss][1])+abs(X1-DX[ss][1])+V[3]+abs(Y2-DY[ts-1][1])+abs(X2-(DX[ts-1][1]+1))+ts-ss);
			cout<<ret<<endl;
			
			
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}