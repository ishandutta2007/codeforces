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

int n;
pi card[105];
int state[105];
int conv[300];

int main(){
	conv['R']=0;conv['G']=1;conv['B']=2;conv['Y']=3;conv['W']=4;
	cin>>n;
	REP(i,n){
		char tmp[5];scanf("%s",tmp);
		card[i].fr=conv[tmp[0]];
		card[i].sc=tmp[1]-'1';
	}
	sort(card,card+n);
	n=unique(card,card+n)-card;

	int res=10;
	dump(n);
	REP(i,1<<10){
		CLR(state);
		REP(j,n) {
			REP(k,10) if(i>>k&1){
				if(k<5 && k==card[j].fr) state[j]|=(1<<k);
				if(k>=5 && k-5==card[j].sc) state[j]|=(1<<k);
			}
		}
		sort(state,state+n);
		int fail=0;
		REP(j,n-1) if(state[j+1]==state[j]) fail=1;
		if(!fail) chmin(res,__builtin_popcount(i));
	}
	cout<<res<<endl;


	return 0;
}