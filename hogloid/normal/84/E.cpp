#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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
int n,m,k;
char s[55][55];
string FAIL;
int id[30];
string ans;
pi prev[55][55];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int sx,sy,gx,gy;
void dfs2(vector<vector<pi> >& ps){
	vector<vector<pi> > nxt;

	while(!ps.empty()){
		nxt.clear();
		REP(i,ps.size()){
			REP(c,k){
				vector<pi> tmp;
				REP(j,ps[i].size()){
					int x=ps[i][j].sc,y=ps[i][j].fr;

					REP(d,4){
						int px=x+dx[d],py=y+dy[d];
						if(px<0 || py<0 || px>=m || py>=n 
		|| prev[py][px].fr!=-1 ||(s[py][px]!='T' && id[s[py][px]-'a']!=c)) continue;
						tmp.pb(mp(py,px));
						prev[py][px]=ps[i][j];
					}
				}
				if(!tmp.empty()) nxt.pb(tmp);
			}
		}
		ps=nxt;
	}
}


string solve(){
	memset(prev,-1,sizeof(prev));
	
	vector<vector<pi > > tmp;tmp.pb(vector<pi>(1,mp(sy,sx)));
	prev[sy][sx]=mp(-2,-2);

	dfs2(tmp);

	if(prev[gy][gx].fr==-1) return FAIL;

	string path;
	pi cur=mp(gy,gx);
	while(cur!=mp(sy,sx)){
		cur=prev[cur.fr][cur.sc];
		if(s[cur.fr][cur.sc]!='S') path+=s[cur.fr][cur.sc];
	}
	reverse(ALL(path));
	return path;
}
bool cmp(const string& a,const string& b){
	if(a.size()!=b.size()) return a.size()<b.size();
	return a<b;
}

void dfs(int d,int done){
	if(d==26){
		if(done==k) ans=min(ans,solve(),cmp);
		return;
	}

	if(done<k){
		id[d]=done;
		dfs(d+1,done+1);
	}
	id[d]=-1;
	dfs(d+1,done);
}
int main(){
	cin>>n>>m>>k;
	REP(i,n) scanf("%s",s[i]);

	REP(i,n) REP(j,m){
		if(s[i][j]=='S'){
			sx=j;sy=i;
		}
		if(s[i][j]=='T'){
			gx=j;gy=i;
		}
	}
	REP(i,n*m+1) FAIL+='z';
	ans=FAIL;

	memset(id,-1,sizeof(id));
	
	dfs(0,0);


	if(ans==FAIL) ans="-1";
	cout<<ans<<endl;
	return 0;
}