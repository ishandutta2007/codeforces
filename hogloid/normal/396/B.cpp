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


#ifndef ONLINE_JUDGE
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
typedef unsigned long long int lint;
typedef pair<lint,lint> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
//const int INF=5e8;
int isprime(int a){
	if(a==1) return false;
	for(int i=2;i*i<=a;++i) if(a%i==0) return false;
	return true;
}
pi add(const pi& a,const pi& b){
	lint g=__gcd(a.sc,b.sc);
	pi res=mp(b.sc/g*a.fr+a.sc/g*b.fr,a.sc/g*b.sc);
	g=__gcd(res.fr,res.sc);
	res.fr/=g;res.sc/=g;
	return res;
}

pi make(int a,int k){
	lint L=a,R=a+1;
	while(!isprime(L)) --L;
	while(!isprime(R)) ++R;
	return mp(k,L*R);
}


int main(){
	pi sum=mp(0,1);
	for(int i=2;i<=10;++i){
		sum=add(sum,make(i,1));
		dump(i);dump(sum);
	}

	int t;cin>>t;
	REP(hoge,t){
		int n;cin>>n;

		lint lb=n,ub;
		while(isprime(lb+1)==false) --lb;
		pi res=mp(lb-1,lb*2+2);
		dump(res);
		ub=lb+2;
		while(!isprime(ub)) ++ub;
		dump(lb);dump(ub);

		res.fr*=ub;
		res.sc*=ub;

		
		res.fr+=(n-lb)*2ll;
		lint g=__gcd(res.fr,res.sc);
		res.fr/=g;res.sc/=g;
		cout<<res.fr<<'/'<<res.sc<<endl;
	}


	return 0;
}