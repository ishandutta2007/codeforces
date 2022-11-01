#define DEB

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
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
int ar[5005];

int mini[5005][5005];


int rec(int l,int r,int lev){
	if(r-l<=0) return 0;
	int piv=mini[l][r];
	int res=r-l;
	chmin(res,rec(l,piv,ar[piv])+rec(piv+1,r,ar[piv])+ar[piv]-lev);

	return res;
}
	


int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	
	REP(i,n){
		mini[i][i+1]=i;
		REPN(j,n,i+1){
			if(ar[j]<ar[mini[i][j]]) mini[i][j+1]=j;
			else mini[i][j+1]=mini[i][j];
		}
	}


	cout<<rec(0,n,0)<<endl;

	return 0;
}