#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
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
char buf[20][20];
lint B=100000007;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
lint makehash(vector<pi>& a){
	lint res=0;
	REP(i,a.size()){
		res=res*B*B+a[i].fr*B+a[i].sc;
	}
	return res;
}
int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);
	vector<pi> init;
	int size=0;
	REP(i,h) REP(j,w) if(buf[i][j]>='1' && buf[i][j]<='9'){
		size=max(size,(int)(buf[i][j]-'0'));
	}
	init.resize(size);
	REP(i,h) REP(j,w) if(buf[i][j]>='1' && buf[i][j]<='9'){
		init[(int)(buf[i][j]-'1')]=mp(i,j);
	}

	queue<vector<pi> >q;
	q.push(init);
	map<int,int>memo;
	memo[makehash(init)]=0;
	int res=-1;
	while(!q.empty()){
		vector<pi> cur=q.front();q.pop();
		if(buf[cur[0].fr][cur[0].sc]=='@'){
			res=memo[makehash(cur)];break;
		}
		vector<pi> tmp;
		REP(i,4){
			int px=cur[0].sc+dx[i],py=cur[0].fr+dy[i];
			if(px<0 || py<0 || px>=w || py>=h ||
				buf[py][px]=='#') continue;
			tmp=cur;
			tmp.pop_back();
			int fail=0;
			REP(j,tmp.size()) if(tmp[j]==mp(py,px)){
				fail=1;break;
			}
			if(!fail){
				tmp.insert(tmp.begin(),mp(py,px));
				if(memo.count(makehash(tmp))==0){
					memo[makehash(tmp)]=memo[makehash(cur)]+1;
					q.push(tmp);
				}
			}
		}
	}
	printf("%d\n",res);

	return 0;
}