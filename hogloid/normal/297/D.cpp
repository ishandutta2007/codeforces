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
int h,w,k;
char tmp[1005];
int row[1005][1005],col[1005][1005];

int row2[1005][1005],col2[1005][1005];
void rot(){
	REP(i,h) REP(j,w-1){
		row2[j][h-1-i]=col[i][j];
	}
	REP(i,h-1) REP(j,w){
		col2[j][h-2-i]=row[i][j];
	}
	swap(h,w);	
	REP(i,h) REP(j,w) row[i][j]=row2[i][j],col[i][j]=col2[i][j];
}

int res[1005][1005],res2[1005][1005];

void rot2(){
	REP(i,h) REP(j,w) res2[w-1-j][i]=res[i][j];

	swap(h,w);
	REP(i,h) REP(j,w) res[i][j]=res2[i][j];
}

int main(){
	cin>>h>>w>>k;
	REP(r,h){
		scanf("%s",tmp);
		REP(j,w-1) col[r][j]=(tmp[j]=='E'?1:0);
		
		if(r==h-1) break;
		scanf("%s",tmp);
		REP(j,w) row[r][j]=(tmp[j]=='E'?1:0);
	}

	if(k==1){
		int fail=0,all=h*(w-1)+w*(h-1);
		REP(i,h) REP(j,w-1) if(col[i][j]==0){
			fail++;
		}
		REP(i,h-1) REP(j,w) if(row[i][j]==0){
			fail++;
		}
		if(fail*4>all) puts("NO");
		else{
			puts("YES");
			REP(i,h) REP(j,w) printf("%d%c",1,j==w-1?'\n':' ');
		}
		return 0;
	}
	
	bool flag=false;
	if(h>w){
		rot();
		flag=true;
	}

	REP(i,h) REP(j,w-1){
		res[i][j+1]=res[i][j];
		if(!col[i][j]) res[i][j+1]^=1;
	}


	REP(i,h-1){
		int cnt=0;
		REP(j,w) if((res[i][j]^res[i+1][j])^row[i][j]^1) ++cnt;
		if(cnt*2>=w){
			REP(j,w) res[i+1][j]^=1;
		}
	}
	if(flag) rot2();
	puts("YES");
	REP(i,h) REP(j,w) printf("%d%c",res[i][j]+1,j==w-1?'\n':' ');
	return 0;
}