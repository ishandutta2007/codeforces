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

int h,w;
int k;

int buf[105][105],tmp[105][105];
int main(){
	cin>>h>>w>>k;
	REP(i,h) REP(j,w){
		if(h>=w) cin>>buf[i][j];
		else cin>>buf[j][i];
	}
	if(h<w) swap(h,w);

	REP(i,h) debug(buf[i],buf[i]+w);
	

	int res=1000;
	if(h>k){
		REP(i,h){
			int difsum=0;
			REP(j,h){
				int dif=0;
				REP(j2,w) if(buf[j][j2]!=buf[i][j2]) ++dif;
				difsum+=min(dif,w-dif);
			}
			chmin(res,difsum);
		}
	}else{
		REP(i,1<<w){
			int difsum=0;
			REP(j,h){
				int dif=0;
				REP(j2,w) if(buf[j][j2]!=(i>>j2&1)) ++dif;
				difsum+=min(dif,w-dif);
			}
			chmin(res,difsum);
		}
	}
	if(res==1000 || res>k) res=-1;

	cout<<res<<endl;


	return 0;
}