
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

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



const int INF=5e8;
	
int n;
pair<pi,pi> ps[4];

void rot(pair<pi,pi>& a){
	int dx=a.fr.fr-a.sc.fr,dy=a.fr.sc-a.sc.sc;
	a.fr.fr=a.sc.fr-dy;
	a.fr.sc=a.sc.sc+dx;
}
pi p[4];
bool check(){
	REP(i,4) p[i]=ps[i].fr;
	
	sort(p,p+4);
	do{
		int dx1=p[1].fr-p[0].fr,dy1=p[1].sc-p[0].sc;
		int dx2=p[3].fr-p[0].fr,dy2=p[3].sc-p[0].sc;

		if(p[2].fr-p[0].fr==dx1+dx2 && p[2].sc-p[0].sc==dy1+dy2 &&
			dx2==-dy1 && dy2==dx1 && dx1!=0){
			return true;
		}
	}while(next_permutation(p+1,p+4));
	return false;
}

int dfs(int ind){
	if(ind==4){
		if(check()) return 0;
		return INF;
	}
	
	int res=INF;
	REP(i,4){
		chmin(res,dfs(ind+1)+i);
		rot(ps[ind]);
	}
	return res;
}


		
int main(){
	cin>>n;
	REP(hoge,n){
		REP(i,4){
			cin>>ps[i].fr.fr>>ps[i].fr.sc>>ps[i].sc.fr>>ps[i].sc.sc;
		}

		int res=dfs(0);
		if(res==INF) res=-1;
		cout<<res<<endl;
	}

		

	return 0;
}