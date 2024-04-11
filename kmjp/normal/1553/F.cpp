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

int T;
int A[603030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> num;
BIT<ll,20> val;


int numnum[606060];
ll V[606060];
const int DI=1000;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	ll ret=0;
	while(T--) {
		cin>>x;
		
		if(x<=DI) {
			// prev % x;
			ret+=V[x];
			
			// x % prev
			for(i=1;i<x;i++) if(numnum[i]) {
				ret+=x%i*(ll)numnum[i];
			}
			
			int mor=num(303030)-num(x);
			ret+=1LL*mor*x;
		}
		else {
			// prev % x;
			for(int cur=0;x*cur<=300000;cur++) {
				ll n=num(x*(cur+1)-1)-num(x*(cur));
				if(n) {
					ll v=val(x*(cur+1)-1)-val(x*(cur));
					ret+=v-n*(x*cur);
				}
			}
			// x % prev
			for(i=1;i<=DI;i++) if(numnum[i]) {
				ret+=x%i*(ll)numnum[i];
			}
			int cur=DI+1;
			while(cur<=300000) {
				y=x/cur;
				int nex;
				if(y==0) nex=505050;
				else nex=x/y;
				
				ll n=num(nex)-num(cur-1);
				if(n) {
					ll v=val(nex)-val(cur-1);
					ret+=n*x-y*v;
				}
				
				cur=nex+1;
			}
			
			
		}
		
		for(i=1;i<=DI;i++) V[i]+=x%i;
		num.add(x,1);
		numnum[x]++;
		val.add(x,x);
		cout<<ret<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}