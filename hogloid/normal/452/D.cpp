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

int k;
int n[5],t[5];

pi state[10005];
int ocu[5];
bool push(int time){
	bool res=true;
	REP(i,k){
		if(state[i].fr==3) continue;
		if(state[i].fr==-1){
			if(ocu[0]<n[0]){
				++ocu[0];
				state[i]=mp(0,time);
			}
		}else{
			int id=state[i].fr;
			if(time-state[i].sc>=t[id] && (id==2 || ocu[id+1]<n[id+1])){
				state[i]=mp(id+1,time);
				++ocu[id+1];
				--ocu[id];
			}
		}
	}
	REP(i,k) if(state[i].fr<3) res=false;
	return res;
}
const int INF=5e8;
int main(){
	cin>>k;
	REP(i,k) state[i]=mp(-1,0);
	REP(i,3) cin>>n[i];
	REP(i,3) cin>>t[i];
	
	int time;
	for(time=0;;){
		if(time==INF) break;
		if(push(time)) break;

		int nxt=INF;
		REP(i,k) if(state[i].fr<3 && state[i].fr>=0){
			pi st=state[i];
			if(time-st.sc<t[st.fr]) chmin(nxt,st.sc+t[st.fr]);
		}
		time=nxt;
	}

	cout<<time<<endl;

	return 0;
}