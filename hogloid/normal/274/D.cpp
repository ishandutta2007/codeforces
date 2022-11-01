#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
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
static const int INF =1000000005;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int r,c;
vector<vector<int> > buf;

set<pi> colS[100005],rowS;
int nottop[100005];

int ans[100005];
int main(){
	cin>>r>>c;
	buf.resize(c,vector<int>(r));
	REP(i,r) REP(j,c){
		int a;scanf("%d",&a);
		buf[j][i]=a;
	}

	swap(r,c);

	REP(i,c){
		int smallest=INF;
		REP(j,r) if(buf[j][i]!=-1){
			smallest=min(smallest,buf[j][i]);
			colS[i].insert(mp(buf[j][i],j));
		}
		REP(j,r) if(buf[j][i]!=-1 && buf[j][i]!=smallest){
			nottop[j]++;
		}
	}
	REP(i,r) rowS.insert(mp(nottop[i],i));
	
	int fail=0;
	REP(i,r){
		pi tmp=*rowS.begin();
		if(tmp.fr!=0){
			fail=1;break;
		}
		rowS.erase(rowS.begin());
		ans[i]=tmp.sc;

		int ii=tmp.sc;
		REP(j,c) if(buf[ii][j]!=-1){
			colS[j].erase(mp(buf[ii][j],ii));
			if(!colS[j].empty()){
				int nxt=colS[j].begin()->fr;
				if(nxt!=buf[ii][j]){
					set<pi>::iterator it=colS[j].begin();
					while(it!=colS[j].end()){
						if(it->fr!=nxt) break;
						
						rowS.erase(mp(nottop[it->sc],it->sc));
						--nottop[it->sc];
						rowS.insert(mp(nottop[it->sc],it->sc));
						++it;
					}
				}
			}
		}
	}

	
	if(fail){
		puts("-1");
		return 0;
	}

	REP(i,r) printf("%d\n",ans[i]+1);

	return 0;
}