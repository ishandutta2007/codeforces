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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<20;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_1_max {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1_max(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int N,M;
string S;
SegTree_1<int,1<<20> bt[2],rep;
SegTree_1_max<int,1<<20> step;

int sum[1101010];
int num[1101010];
int st[1101010];
int trep[1101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>M;
	FOR(i,N) {
		
		sum[i+1]=sum[i]+(S[i]=='?');
		bt[0].update(i,N);
		bt[1].update(i,N);
		
		if(S[i]=='a') {
			bt[(i%2)^1].update(i,i);
		}
		if(S[i]=='b') {
			bt[(i%2)].update(i,i);
		}
	}
	int mstep=0,mrep=0;
	FOR(i,N) {
		if(bt[i%2].getval(i,i+M)>=i+M) {
			num[i]=sum[i+M]-sum[i];
			
			x=step.getval(0,i-M+1);
			st[i]=x+1;
			if(x==0) {
				trep[i]=num[i];
			}
			else {
				y=-1;
				for(j=20;j>=0;j--) {
					if(y+(1<<j)>=i) continue;
					if(step.getval(0,y+(1<<j))<x) y+=1<<j;
				}
				trep[i]=num[i]+rep.getval(y,i-M+1);
			}
			
			if(st[i]>mstep) mstep=st[i],mrep=101010;
			if(st[i]==mstep) mrep=min(mrep,trep[i]);
			
		}
		else {
			num[i]=101010;
			st[i]=0;
			trep[i]=101010;
		}
		
		
		step.update(i,st[i]);
		rep.update(i,trep[i]);
	}
	cout<<mrep<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}