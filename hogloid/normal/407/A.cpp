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

int a,b;

pi leg1[1005],leg2[1005];

int cnt1,cnt2;
void getleg(int a,pi* leg,int& cnt){
	for(int i=1;i<a;++i) for(int j=1;j<a;++j) if(i*i+j*j==a*a) leg[cnt++]=mp(i,j);
}

int main(){
	cin>>a>>b;

	getleg(a,leg1,cnt1);getleg(b,leg2,cnt2);
	dump(cnt1);dump(cnt2);
	REP(i,cnt1) REP(j,cnt2){
		pi A=leg1[i],B=leg2[j];
		if(A.fr*B.sc-A.sc*B.fr==0){
			if(B.fr==A.sc) swap(A,B);
			puts("YES");
			printf("%d %d\n%d %d\n%d %d\n",0,0,A.fr,A.sc,-B.sc,B.fr);
			return 0;
		}
	}
	puts("NO");

	return 0;
}