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

//const int INF=5e8;

int h,w;
int buf[35][35];
int goal[35][35];
pi res[1000005];
int mark[35][35];
int cnt;
int sx,sy;

void up(){
	swap(buf[sy][sx],buf[sy-1][sx]);
	--sy;
	res[cnt++]=mp(sy,sx);
}
void down(){
	swap(buf[sy][sx],buf[sy+1][sx]);
	++sy;
	res[cnt++]=mp(sy,sx);
}
void right(){

	swap(buf[sy][sx+1],buf[sy][sx]);
	++sx;
	res[cnt++]=mp(sy,sx);
}
void left(){
	swap(buf[sy][sx-1],buf[sy][sx]);
	--sx;
	res[cnt++]=mp(sy,sx);
}

int id[35][35],curid=1;
pi back[35][35];
void go(int y,int x){
	++curid;
	queue<pi>q;q.push(mp(sy,sx));
	while(!q.empty()){
		pi cur=q.front();q.pop();
		REPN(dx,2,-1) REPN(dy,2,-1) {
			if(dx==0 && dy==0) continue;
			int px=cur.sc+dx,py=cur.fr+dy;
			if(px<0 || py<0 || px>=w || py>=h || mark[py][px] || id[py][px]==curid) continue;
			q.push(mp(py,px));
			id[py][px]=curid;
			back[py][px]=mp(cur.fr,cur.sc);

			if(mp(py,px)==mp(y,x)){
				goto exi4;
			}
		}
	}
exi4:;
	 prl;
	 vector<pi> way;
	 pi cur=mp(y,x);
	 while(cur!=mp(sy,sx)){
		 way.pb(cur);
		 cur=back[cur.fr][cur.sc];
	 }
	 reverse(ALL(way));
	 REP(i,way.size()){
		 swap(buf[way[i].fr][way[i].sc],buf[sy][sx]);
		 sy=way[i].fr;sx=way[i].sc;
		 res[cnt++]=way[i];
	 }
	 sx=x;sy=y;
}

void moveR(int y,int x){
	mark[y][x]=1;
	go(y,x+1);
	left();
	mark[y][x]=0;
}
void moveL(int y,int x){
	mark[y][x]=1;
	go(y,x-1);
	right();
	mark[y][x]=0;
}
void moveD(int y,int x){
	mark[y][x]=1;
	go(y+1,x);
	up();
	mark[y][x]=0;
}

void moveU(int y,int x){
	mark[y][x]=1;
	go(y-1,x);
	down();
	mark[y][x]=0;
}


void end(){
	puts("-1");
	exit(0);
}
void print(){

	printf("%d\n",cnt-1);
	REP(i,cnt) printf("%d %d\n",res[i].fr+1,res[i].sc+1);
	exit(0);
}


int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w) cin>>buf[i][j];
	REP(i,h) REP(j,w) cin>>goal[i][j];
	if(h<2 || w<2){
		int ar[35]={0},ar2[35]={0};
		int n;
		if(h==1){
			REP(i,w) ar[i]=buf[0][i],ar2[i]=goal[0][i];
			n=w;
		}else{
			REP(i,h) ar[i]=buf[i][0],ar2[i]=goal[i][0];
			n=h;
		}

		REP(i,n) if(ar[i]!=ar2[i]){
			REPN(j,n,i+1) if(ar2[i]==ar[j]){
				dump(i);dump(j);
				rotate(ar+i,ar+j,ar+j+1);

				int fail=0;
				REP(k,n) if(ar[k]!=ar2[k]) fail=1;

				if(!fail){
					for(int k=j;k>=i;--k) res[cnt++]=mp(k,0);
					goto exi3;
				}
				rotate(ar+i,ar+i+1,ar+j+1);
			}
			REPN(j,n,i+1) if(ar2[j]==ar[i]){
				rotate(ar+i,ar+i+1,ar+j+1);
				int fail=0;
				REP(k,n) if(ar[k]!=ar2[k]) fail=1;

				if(!fail){
					for(int k=i;k<=j;++k) res[cnt++]=mp(k,0);
					goto exi3;
				}
				rotate(ar+i,ar+j,ar+j+1);
			}
			break;
		}
		end();
exi3:;
	 	if(w==1) ;
		else REP(i,cnt) {
			swap(res[i].fr,res[i].sc);
		}

		print();

	}
	sx=sy=-1;
	REP(i,h) REP(j,w) if(buf[i][j]==goal[h-1][w-1]){
		sy=i;sx=j;
	}
	if(sx==-1) end();
	res[cnt++]=mp(sy,sx);


	REP(i,h-2) REP(j,w){
		pi pos;
		REP(k,h) REP(l,w) if(!mark[k][l] && mp(k,l)!=mp(sy,sx) && goal[i][j]==buf[k][l]){
			pos=mp(k,l);
			goto exi;
		}
		end();
exi:;
		
		while(pos!=mp(i,j)){
			if(pos.sc<j){
				moveR(pos.fr,pos.sc);++pos.sc;
			}
			else if(pos.sc>j){
				moveL(pos.fr,pos.sc);
				--pos.sc;
			}
			else if(pos.fr>i){
				moveU(pos.fr,pos.sc);
				--pos.fr;
			}
		}
		mark[i][j]=1;
	}

	REP(j,w-1) REPN(i,h,h-2){
		
		dump(i);dump(j);
		dump(mp(sy,sx));
		pi pos;
		REP(k,h) REP(l,w) if(!mark[k][l] && mp(k,l) != mp(sy,sx) && goal[i][j]==buf[k][l]){
			pos=mp(k,l);
			goto exi2;
		}
		end();
exi2:;
	 dump(pos);
	 	
	 	while(pos!=mp(i,j)){
			if(i<pos.fr){
				moveU(pos.fr,pos.sc);
				--pos.fr;
			}
			else if(i>pos.fr) {
				moveD(pos.fr,pos.sc);
				++pos.fr;
			}
			else{
				moveL(pos.fr,pos.sc);
				--pos.sc;
			}
		}
		mark[i][j]=1;
	}

	if(sy<h-1) down();

	if(buf[h-2][w-1]==goal[h-2][w-1]);
	else end();
	
	print();
	return 0;
}