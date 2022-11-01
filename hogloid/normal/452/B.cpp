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
pi pts[4];

void solve(int w,int h){//w>=h
	if(h==0){
		pts[0]=mp(w-1,0);
		pts[1]=mp(0,0);
		pts[2]=mp(w,0);
		pts[3]=mp(1,0);
	}else{
		double planA=sqrt(w*w+(double)h*h)+sqrt(w*w+(double)(h-1)*(h-1))*2,
			   	planB=sqrt(w*w+(double)h*h)*2+w;
		if(planA>planB){
			pts[0]=mp(0,1);
			pts[1]=mp(w,h);
			pts[2]=mp(0,0);
			pts[3]=mp(w,h-1);
		}else{
			pts[0]=mp(0,0);
			pts[1]=mp(w,h);
			pts[2]=mp(0,h);
			pts[3]=mp(w,0);
		}
	}
}
int main(){
	cin>>w>>h;
	if(h>w){
		solve(h,w);
		REP(i,4) swap(pts[i].fr,pts[i].sc);
	}else solve(w,h);
	REP(i,4){
		printf("%d %d\n",pts[i].fr,pts[i].sc);
	}



	return 0;
}