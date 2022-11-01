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

lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}

const int INF=5e8;

int h,w;
char buf[1005][1005];
int sum[1005][1005];
int sy,sx;
int tot;
bool isok(int y,int x,int W,int H){
	if(y+H<=h && x+W<=w && sum[y+H][x+W]-sum[y][x+W]-sum[y+H][x]+sum[y][x]==W*H) return true;
	return false;
}
bool check(int W,int H){
	int cx=sx,cy=sy;
	
	int fail=0;
	int sum=W*H;
	while(1){
		bool right=isok(cy,cx+1,W,H);
		bool down=isok(cy+1,cx,W,H);

		if(right&&down){
			fail=1;break;
		}
		if(!right && !down){
			if(sum==tot);
			else fail=1;
			break;
		}

		if(right){
			++cx;
			sum+=H;
		}
		if(down){
			++cy;
			sum+=W;
		}
	}
	if(fail) return false;
	return true;
}

int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w){
		if(buf[i][j]=='X') ++tot;
		sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+(buf[i][j]=='X'?1:0);
	}

	REP(j,w) REP(i,h) if(buf[i][j]=='X'){
		sy=i;sx=j;
		goto exi;
	}
exi:;
	int Xlen=0,Ylen=0;
	while(sx+Xlen<w && buf[sy][sx+Xlen]=='X') ++Xlen;
	while(sy+Ylen<h && buf[sy+Ylen][sx]=='X') ++Ylen;
	
	int res=INF;
	REP(i,Ylen){
		if(check(Xlen,i+1)) chmin(res,Xlen*(i+1));
	}
	REP(i,Xlen) if(check(i+1,Ylen)) chmin(res,(i+1)*Ylen);
	
	if(res==INF) res=-1;
	cout<<res<<endl;
	return 0;
}