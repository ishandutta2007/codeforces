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

int buf[405][405];
set<int> pos[160005];
int h,w;


int downok[405];//...downok)
int down2[405];

int dq[405];

bool check(int md){
	//down2[i]:=min{downok[i],downok[i+1]...downok[i+md-1]}
	int st=0,en=0;
	REP(k,h){
		if(st<en && dq[st]<k-md+1) ++st;
		while(st<en && downok[dq[en-1]]>downok[k]) --en;
		dq[en++]=k;
		if(k-md+1>=0) down2[k-md+1]=downok[dq[st]];

	}

	REP(k,h-md+1) if(down2[k]>=k+md) {
		return true;
	}
	return false;
}

int Up[405][405],Down[405][405];
int lastapp[160005];
int MX=160005;
int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w) scanf("%d",&buf[i][j]);
	

	int res=0;

	REP(i,h) REP(j,w){
		Up[i][j]=-1;
		Down[i][j]=h+1;
	}

	for(int i=w-1;i>=0;--i){
		dump(i);
		REP(j,h+1) downok[j]=h;
		

		REP(j,MX) lastapp[j]=-1;
		REP(j,h) REPN(k,w,i){
			chmax(Up[j][k],lastapp[buf[j][k]]);
			if(k==i) lastapp[buf[j][k]]=j;
		}

		REP(j,MX) lastapp[j]=h+1;
		for(int j=h-1;j>=0;--j) REPN(k,w,i){
			chmin(Down[j][k],lastapp[buf[j][k]]);
			if(k==i) lastapp[buf[j][k]]=j;
		}
		
		int len=h;
		REP(j,h) debug(Down[j],Down[j]+w);
		REP(j,h) debug(Up[j],Up[j]+w);
		REPN(j,w,i){
			dump(j);
			REP(k,h){
				int up=Up[k][j];
				if(up>=0) chmin(downok[up],k);
				int down=Down[k][j];
				if(down<h) chmin(downok[k],down);
			}
			debug(downok,downok+h);
			while(len>0 && !check(len)) --len;
			chmax(res,len*(j+1-i));
			dump(res);
		}
	}
	cout<<res<<endl;

	return 0;
}