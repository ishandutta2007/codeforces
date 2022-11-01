#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =1050000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int xzip[3005],yzip[3005];
int conv[300];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
pair<pi,pi> move[1005];
int buf[3005][3005];
#define FIND(it,len,key) (lower_bound(it,it+len,key)-it)
int main(){
	conv['R']=0;conv['U']=1;conv['L']=2;conv['D']=3;
	cin>>n;
	int cx=0,cy=0;
	int xn=0,yn=0;
	REP(i,n){
		char tmp[10];scanf("%s",tmp);
		int dir=conv[tmp[0]];
		int ab;scanf("%d",&ab);
		move[i].fr=mp(cy,cx);
		cx+=dx[dir]*ab;
		cy+=dy[dir]*ab;
		move[i].sc=mp(cy,cx);

		xzip[xn++]=cx;yzip[yn++]=cy;
		xzip[xn++]=cx+1;yzip[yn++]=cy+1;
	}
	xzip[xn++]=0;yzip[yn++]=0;
	xzip[xn++]=1;yzip[yn++]=1;
	xzip[xn++]=-INF;yzip[yn++]=-INF;
	xzip[xn++]=INF;yzip[yn++]=INF;
	
	sort(xzip,xzip+xn);
	sort(yzip,yzip+yn);
	xn=unique(xzip,xzip+xn)-xzip;
	yn=unique(yzip,yzip+yn)-yzip;
	REP(i,n){
		move[i].fr.fr=FIND(yzip,yn,move[i].fr.fr);
		move[i].sc.fr=FIND(yzip,yn,move[i].sc.fr);
		move[i].fr.sc=FIND(xzip,xn,move[i].fr.sc);
		move[i].sc.sc=FIND(xzip,xn,move[i].sc.sc);

		if(move[i].fr.fr==move[i].sc.fr){
			if(move[i].fr.sc>move[i].sc.sc) swap(move[i].fr.sc,move[i].sc.sc);
			REPN(j,move[i].sc.sc+1,move[i].fr.sc) buf[move[i].fr.fr][j]=1;
		}else{
			if(move[i].fr.fr>move[i].sc.fr) swap(move[i].fr.fr,move[i].sc.fr);
			REPN(j,move[i].sc.fr+1,move[i].fr.fr) buf[j][move[i].fr.sc]=1;
		}
	}
	queue<pi> q;q.push(mp(0,0));buf[0][0]=-1;
	while(!q.empty()){
		pi cur=q.front();q.pop();
		REP(i,4){
			int px=cur.sc+dx[i],py=cur.fr+dy[i];
			if(px<0 || py<0 || px>=xn-1 || py>=yn-1 || buf[py][px]) continue;
			buf[py][px]=-1;
			q.push(mp(py,px));
		}
	}
	lint res=0;
	REP(i,yn-1) REP(j,xn-1) if(buf[i][j]>=0){
		lint area=(xzip[j+1]-xzip[j])*(lint)(yzip[i+1]-yzip[i]);
		res+=area;
	}
	cout<<res<<endl;

	return 0;
}