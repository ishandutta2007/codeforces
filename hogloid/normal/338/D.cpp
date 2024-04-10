#define DEB

#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
//const int INF=5e8;
lint extgcd(lint a,lint b,lint& x,lint& y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	lint d=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

lint n,m;
int k;
lint ar[10005];

lint M=1e6;
void mult(lint&a,lint b,lint mod){
	a=(a%mod+mod)%mod;
	b=(b%mod+mod)%mod;
	
	lint prev=a;
	a=a*M%mod*(b/M)%mod;
	a=(a+prev*(b%M))%mod;
}

bool solve(){
	cin>>n>>m>>k;
	REP(i,k) cin>>ar[i];
	lint lcm=ar[0];
	REPN(i,k,1){
		double cur=lcm*(double)ar[i]/__gcd(ar[i],lcm);
		if(cur>2e12) return false;
		lcm=lcm/__gcd(ar[i],lcm)*ar[i];
	}
	if(lcm>n) return false;
	lint mod1=ar[0],a1=0;
	REPN(i,k,1){

		lint mod2=ar[i],a2=-i;
		
		lint b1,b2;
		lint g=extgcd(mod1,mod2,b1,b2);
		mod2=mod2/g*mod1;
		
		if((a2-a1)%g) return false;
		mult(b1,(a2-a1)/g,mod2);
		mult(b2,(a2-a1)/g,mod2);
		
		mult(b1,mod1,mod2);
		a1=(a1+b1)%mod2;
		mod1=mod2;
	}
	if(a1==0) a1=mod1;
	dump(a1);dump(lcm);
	REP(i,k){
		if(__gcd((a1+i),lcm)!=ar[i]) return false;
	}
	if(a1+k-1>m) return false;
	return true;
}

int main(){
	puts(solve()?"YES":"NO");
	return 0;
}