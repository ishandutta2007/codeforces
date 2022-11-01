#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
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
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
char buf[105][10005];
bool wall(int y,int x){
	if(x<0 || x>=m) return true;
	return (buf[y][x]=='#');
}
int main(){
	cin>>n>>m;
	REP(i,n) scanf("%s",buf[i]);
	
	int cx=0,cy=0,d=1;
	lint time=0;
	int flag=1;
	int l=cx,r=cx;
	while(cy<n-1){
		if(buf[cy+1][cx]=='.'){
			++cy;
			++time;
			l=r=cx;
			continue;
		}
		if(wall(cy,l-1) &&  wall(cy,r+1)){
			dump(cy);
			time=-1;break;
		}
		int px=cx+d;
		if(wall(cy,px)){
			d*=-1;
			++time;
			if(d>0){
				time+=r-cx;
				cx=r;
			}else{
				time+=cx-l;
				cx=l;
			}
		}else if(buf[cy][px]=='+'){
			buf[cy][px]='.';
			++time;
			d*=-1;
			if(d>0){
				time+=r-cx;
				cx=r;
			}else{
				time+=cx-l;
				cx=l;
			}
		}else{
			cx=px;
			++time;
			if(d>0) r=px;
			else l=px;
		}
	}

	if(time==-1) puts("Never");
	else cout<<time<<endl;
	return 0;
}