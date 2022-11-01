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
const lint INF=1e18;
lint a,b;
int main(){
	cin>>a>>b;

	if(a==0){
		cout<<-b*b<<endl;
		REP(i,b) putchar('x');
		putchar('\n');
		return 0;
	}

	if(b<=1){
		cout<<a*a-b<<endl;
		REP(i,b) putchar('x');
		REP(i,a) putchar('o');
		putchar('\n');
		return 0;
	}
	
	lint res=-INF;
	int div;
	for(int i=1;i<=min(a,b-1);++i){
		lint blk=i+1;
		lint tmp=0;
		tmp-=(b/blk)*(b/blk)*(blk-b%blk);
		dump(b/blk);dump(blk-b%blk);
		tmp-=(b/blk+1)*(b/blk+1)*(b%blk);

		tmp+=i-1;
		tmp+=(a-i+1)*(a-i+1);

		if(res<tmp){
			res=tmp;
			div=i;
		}
	}
	dump(div);

	cout<<res<<endl;
	string ans;
	{
		lint blk=div+1;
		REP(i,blk){
			if(i<b%blk){
				REP(j,b/blk+1) ans+='x';
			}else{
				REP(j,b/blk) ans+='x';
			}
			if(i==div) break;
			if(i==0){
				REP(j,a-div+1) ans+='o';
			}
			else{
				ans+='o';
			}
		}
	}
	cout<<ans<<endl;

		

	return 0;
}