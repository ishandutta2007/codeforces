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

int n,k;
int main(){
	cin>>n>>k;
	if(n/2>k) puts("-1");
	else if(n==1){
		if(k==0) puts("1");
		else puts("-1");
	}else{
		int ave=k/(n/2);
		int add=k%(n/2);
		
		dump(ave);dump(add);
		vector<int> ar;
		set<int> used;
		int cnt=1;
		REP(i,add){
			ar.pb((ave+1)*cnt);++cnt;
			ar.pb((ave+1)*cnt);++cnt;
		}
		REP(i,ar.size()) used.insert(ar[i]);
		
		cnt=1;
		REP(i,n/2-add){
			while(!(!used.count(ave*cnt) && !used.count(ave*(cnt+1)))) ++cnt;
			used.insert(ave*cnt);
			ar.pb(ave*cnt);++cnt;
			used.insert(ave*cnt);
			ar.pb(ave*cnt);++cnt;
		}

		if(n&1){
			for(int i=1;i<=10000000;++i) if(!used.count(i)){
				ar.pb(i);
				break;
			}
		}
		REP(i,ar.size()) printf("%d%c",ar[i],i==ar.size()-1?'\n':' ');
	}

	return 0;
}