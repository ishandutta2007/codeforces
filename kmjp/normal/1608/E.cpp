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
int X[301010],Y[301010],C[301010],T[301010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,19> bt[2];

vector<pair<int,int>> ev[301010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> Xs,Ys;
	
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>T[i];
		Xs.push_back(X[i]);
		Ys.push_back(Y[i]);
		T[i]--;
	}
	Xs.push_back(1<<30);
	Xs.push_back(-1<<30);
	Ys.push_back(1<<30);
	Ys.push_back(-1<<30);
	sort(ALL(Xs));
	sort(ALL(Ys));
	FOR(i,N) {
		X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
		Y[i]=lower_bound(ALL(Ys),Y[i])-Ys.begin();
	}
	
	
	int ma=0;
	int step;
	FOR(step,4) {
		FOR(i,N) {
			x=N+1-Y[i];
			y=X[i];
			X[i]=x;
			Y[i]=y;
			assert(x>=1&&x<=N);
			assert(y>=1&&y<=N);
		}
		
		
		vector<int> V={0,1,2};
		do {
			vector<pair<int,int>> Vs;
			FOR(i,N+3) ev[i].clear();
			assert(bt[0](N+2)==0);
			assert(bt[1](N+2)==0);
			
			FOR(i,N) {
				C[i]=V[T[i]];
				Vs.push_back({Y[i],C[i]});
				ev[Y[i]].push_back({X[i],C[i]});
				if(C[i]!=0) bt[C[i]-1].add(X[i],1);
			}
			
			//0,1,2;
			sort(ALL(Vs));
			int ret=0;
			for(i=20;i>=0;i--) if(3*(ret+(1<<i))<=N) {
				x=ret+(1<<i);
				y=0;
				int pre=-1;
				FORR2(a,c,Vs) {
					if(a>=pre&&y<x&&c==0) {
						y++;
						if(y==x) pre=a+1;
					}
					if(a>=pre&&y>=x&&y<2*x&&c==1) {
						y++;
						if(y==2*x) pre=a+1;
					}
					if(a>=pre&&y>=2*x&&y<3*x&&c==2) y++;
				}
				if(y==3*x) ret+=1<<i;
			}
			ma=max(ma,ret);
			
			ret=0;
			int n0=0;
			int fin=0;
			for(y=1;y<=N+2;y++) {
				FORR2(x,c,ev[y]) {
					if(c==0) n0++;
					if(c==1) bt[0].add(x,-1);
					if(c==2) bt[1].add(x,-1);
				}
				
				if(n0<=ma) continue;
				if(fin==0) {
					x=0;
					for(i=17;i>=0;i--) if((x+(1<<i))<=N) {
						int a=bt[0](x+(1<<i));
						int b=bt[1](N+2)-bt[1](x+(1<<i));
						if(a<=b) x+=1<<i;
					}
					int a=bt[0](x);
					int b=bt[1](N+2)-bt[1](x);
					int m1=min(a,b);
					ma=max(ma,min({n0,a,b}));
					
					a=bt[0](x+1);
					b=bt[1](N+2)-bt[1](x+1);
					int m2=min(a,b);
					ma=max(ma,min({n0,a,b}));
				}
			}
			
			
		} while(next_permutation(ALL(V)));
		
		
		
	}
	
	
	cout<<ma*3<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}