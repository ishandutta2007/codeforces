#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
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
int n,d;
lint x;

lint getNextX(){
 x = (x * 37 + 10007) % 1000000007;
 return x;
}

int a[100005],b[100005];
void initAB(){
	REP(i,n) a[i]=i+1;
	REP(i,n) swap(a[i],a[getNextX()%(i+1)]);
	REP(i,n){
		if(i<d) b[i]=1;
		else b[i]=0;
	}
	REP(i,n) swap(b[i],b[getNextX()%(i+1)]);
}



int c[100005];

pi ar2[100005];

vector<int> enpos;
int main(){
	cin>>n>>d>>x;
	initAB();
	
	REP(i,n) if(b[i]) enpos.pb(i);
	if(d*(lint)d>=n){
		set<pi,greater<pi> > ever;
		REP(i,n){
			ever.insert(mp(a[i],i));
			auto it=ever.begin();
			c[i]=0;
			while(it!=ever.end()){
				if(b[i-it->sc]==1){
					c[i]=it->fr;
					break;
				}
				++it;
			}
		}
	}else{
		REP(i,n){
			c[i]=0;
			REP(j,enpos.size()){
				if(i>=enpos[j]) chmax(c[i],a[i-enpos[j]]);
			}
		}
	}
	REP(i,n) printf("%d\n",c[i]);
	return 0;
}