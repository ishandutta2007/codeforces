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

int N,K;
int T[202020];
ll TS[202020];
double S[202020];
double Rev[202020];
double RS[202020];
double from[202020];
double to[202020];

template<typename V> struct ConvexHull {
	deque<pair<V,V>> Q;
	int cmptype=0; // 0-min 1-max
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) { // max or min
		return cmptype^((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		if(cmptype==1) reverse(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			((calc(Q[M],x)<=calc(Q[M+1],x))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(i=1;i<=N;i++) {
		cin>>T[i];
		TS[i]=TS[i-1]+T[i];
		Rev[i]=Rev[i-1]+1.0/T[i];
		from[i]=S[i]=S[i-1]+TS[i]*1.0/T[i];
	}
	
	for(i=2;i<=K;i++) {
		ConvexHull<double> ch;
		for(j=1;j<=N;j++) {
			//if(j>i) _P("query %lf : %lf+%lf : %lf\n",Rev[j],-ch.query(Rev[j]),S[j],-ch.query(Rev[j])+S[j]);
			if(j<=i) to[j]=j;
			else to[j]=-ch.query(Rev[j])+S[j];
			/*
			if(j==4) {
				for(double x=0;x<=5.0;x+=0.1) _P("%lf %lf\n",x,ch.query(x));
				FORR(r,ch.Q) _P("<%lf:%lf>\n",r.first,r.second);
			}
			*/
			ch.add(TS[j],-(from[j]+Rev[j]*TS[j]-S[j]));
			//_P("%lld %lf ",TS[j],-(from[j]+Rev[j]*TS[j]-S[j]));
		}
		//_P("\n");
		swap(from,to);
	}
	
	_P("%.12lf\n",(double)from[N]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}