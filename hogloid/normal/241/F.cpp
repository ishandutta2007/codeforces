#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<assert.h>
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
int h,w;
int k;
char buf[105][105];
int sx,sy,gx,gy;
int memo[35][35];
pi place[35];
int get(int i,int j){
	int& res=memo[i][j];
	if(res!=-1) return res;
	res=0;
	if(!(place[i].fr==place[j].fr || place[i].sc==place[j].sc)){
		while(1){}
	}
	if(place[i].fr==place[j].fr){
		if(place[i].sc<place[j].sc){
		REPN(k,place[j].sc,place[i].sc){
			if(buf[place[i].fr][k]>='1' && buf[place[i].fr][k]<='9') res+=buf[place[i].fr][k]-'0';
			else ++res;
		}
		}else{
		for(int k=place[i].sc;k>place[j].sc;--k){
			if(buf[place[i].fr][k]>='1' && buf[place[i].fr][k]<='9') res+=buf[place[i].fr][k]-'0';
			else ++res;
		}
		}
	}else{
		if(place[i].fr<place[j].fr){
		REPN(k,place[j].fr,place[i].fr){
			if(buf[k][place[i].sc]>='1' && buf[k][place[i].sc]<='9') res+=buf[k][place[i].sc]-'0';
			else ++res;
		}
		}else{
		for(int k=place[i].fr;k>place[j].fr;--k){
			if(buf[k][place[i].sc]>='1' && buf[k][place[i].sc]<='9') res+=buf[k][place[i].sc]-'0';
			else ++res;
		}
		}
	}
	return res;
}
pi getplace(int i,int j,int K){
	pi ans;
	int res=0;
	if(place[i].fr==place[j].fr){
		if(place[i].sc<place[j].sc){
		REPN(k,place[j].sc,place[i].sc){
			ans=mp(place[i].fr,k);
			if(buf[place[i].fr][k]>='1' && buf[place[i].fr][k]<='9') res+=buf[place[i].fr][k]-'0';
			else ++res;

			if(res>K) return ans;
		}
		}else{
		for(int k=place[i].sc;k>place[j].sc;--k){
			ans=mp(place[i].fr,k);
			if(buf[place[i].fr][k]>='1' && buf[place[i].fr][k]<='9') res+=buf[place[i].fr][k]-'0';
			else ++res;
			if(res>K) return ans;
		}
		}

	}else{
		if(place[i].fr<place[j].fr){
		REPN(k,place[j].fr,place[i].fr){
			ans=mp(k,place[i].sc);
			if(buf[k][place[i].sc]>='1' && buf[k][place[i].sc]<='9') res+=buf[k][place[i].sc]-'0';
			else ++res;
			if(res>K) return ans;
		}
		}else{
		for(int k=place[i].fr;k>place[j].fr;--k){
			ans=mp(k,place[i].sc);
			if(buf[k][place[i].sc]>='1' && buf[k][place[i].sc]<='9') res+=buf[k][place[i].sc]-'0';
			else ++res;
			if(res>K) return ans;
		}
		}
	}
}
char s[1005];
vector<int> junc;
int main(){
	cin>>h>>w>>k;
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w) if(buf[i][j]>='a' && buf[i][j]<='z'){
		place[buf[i][j]-'a']=mp(i,j);
	}

	cin>>sy>>sx;
	scanf("%s",s);
	cin>>gy>>gx;
	--sx;--sy;--gx;--gy;
	place[30]=mp(sy,sx);
	place[31]=mp(gy,gx);
	memset(memo,-1,sizeof(memo));

	junc.pb(30);
	int len=strlen(s);
	REP(i,len){
		junc.pb(s[i]-'a');
	}
	junc.pb(31);

	int ever=0;
	pi answer;
	int flag=0;
	REP(i,junc.size()-1){
		int cur=get(junc[i],junc[i+1]);
		if(ever+cur>k){
			answer=getplace(junc[i],junc[i+1],k-ever);
			flag=1;
			break;
		}else{
			ever+=cur;
		}
	}
	if(!flag) answer=mp(gy,gx);
	
	printf("%d %d\n",answer.fr+1,answer.sc+1);


	return 0;
}