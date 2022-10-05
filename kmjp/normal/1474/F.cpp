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


int N,X;
ll S[55];
const ll mo=998244353;

const int MAT=55;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	int pre=0;
	FOR(i,N) {
		cin>>x;
		if(x==0) {
			i--,N--;
			continue;
		}
		if(pre==0) {
			S[i+1]=S[i]+x;
			pre=x;
		}
		else if((x>0)==(pre>0)) {
			S[i]+=x;
			i--,N--;
		}
		else {
			S[i+1]=S[i]+x;
			pre=x;
		}
	}
	S[N+1]=S[N];
	
	
	ll ma=0,mi=0,d=0;
	vector<ll> V;
	FOR(i,N+1) {
		V.push_back(S[i]);
		V.push_back(S[i]-1);
		V.push_back(S[i]+1);
		ma=max(ma,S[i]);
		mi=min(mi,S[i]);
		d=max(d,S[i]-mi);
	}
	
	if(d==0) {
		cout<<1<<" "<<(-S[N]+1)%mo<<endl;
		return;
	}
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	Mat A;
	FOR(y,N+1) FOR(x,y) if(S[y]-S[x]==d) A.v[x][x]=1;
	FOR(i,V.size()-1) {
		ll a=V[i];
		ll b=V[i+1];
		
		{
			Mat B;
			mi=0;
			FOR(j,N+1) {
				mi=min(mi,S[j]);
				if(mi==S[j]&&b<=mi) B.v[j][j]=1;
				if(S[j]<S[j+1]&&S[j]<=a&&b<S[j+1]) B.v[j][j]=1;
				if((S[j]<=a&&a<=S[j+1])||(S[j]>=a&&S[j+1]<=a)) {
					for(k=j+1;k<N;k++) {
						if((S[k]<=b&&b<S[k+1])||(S[k]>=b&&S[k+1]<b)) {
							B.v[k][j]=1;
						}
					}
					if(b==S[N]) B.v[N][j]=1;
				}
			}
			ma=-1LL<<60;
			for(j=N;j>=0;j--) {
				ma=max(ma,S[j]);
				if(S[j]==ma&&a>=S[j]) B.v[j][j]=1;
			}
			B=powmat(b-a,B,N+1);
			A=mulmat(B,A,N+1);
		}
	}
	ll ret=0;
	FOR(y,N+1) FOR(x,y) if(S[y]-S[x]==d) ret+=A.v[y][x];
	cout<<(d+1)<<" "<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}