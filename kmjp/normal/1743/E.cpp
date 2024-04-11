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


ll P[2];
ll T[2];
ll H,S;
map<ll,ll> M1[5050],M2[5050];

ll ret=1LL<<60;
void up1(int h,ll na,ll v) {
	if(h>=H) {
		ret=min(ret,v);
	}
	else {
		if(M1[h].count(na)==0) M1[h][na]=1LL<<60;
		M1[h][na]=min(M1[h][na],v);
	}
}
void up2(int h,ll na,ll v) {
	if(h>=H) {
		ret=min(ret,v);
	}
	else {
		if(M2[h].count(na)==0) M2[h][na]=1LL<<60;
		M2[h][na]=min(M2[h][na],v);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P[0]>>T[0];
	cin>>P[1]>>T[1];
	cin>>H>>S;
	
	M1[0][T[1]]=0;
	FOR(i,H) {
		ll pre=1LL<<60;
		FORR2(a,b,M1[i]) {
			if(b>=pre) continue;
			pre=b;
			// laser1
			up1(i+P[0]-S,max(0LL,a-T[0]),b+T[0]);
			// laser2
			up2(i+P[1]-S,max(T[0]-a,0LL),b+a);
			// laserboth
			ll nt=max(T[0],a);
			up1(i+P[0]+P[1]-S,T[1],b+nt);
		}
		pre=1LL<<60;
		FORR2(a,b,M2[i]) {
			if(b>=pre) continue;
			pre=b;
			// laser2
			up2(i+P[1]-S,max(0LL,a-T[1]),b+T[1]);
			// laser2
			up1(i+P[0]-S,max(T[1]-a,0LL),b+a);
			// laserboth
			ll nt=max(T[1],a);
			up1(i+P[0]+P[1]-S,T[1],b+nt);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}