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

pi back[75][75][75];
int n;
char g[75][75];

void solve(int vs[3]){
	vector<pi> way;

	while(back[vs[0]][vs[1]][vs[2]].fr!=-2){
		pi d=back[vs[0]][vs[1]][vs[2]];
		way.pb(mp(d.sc,vs[d.fr]));
		vs[d.fr]=d.sc;
	}
	reverse(ALL(way));
	cout<<way.size()<<endl;
	REP(i,way.size()) printf("%d %d\n",way[i].fr+1,way[i].sc+1);
}
int main(){
	cin>>n;
	int a,b,c;cin>>a>>b>>c;--a;--b;--c;
	REP(i,n) scanf("%s",g[i]);
	memset(back,-1,sizeof(back));
	back[a][b][c]=mp(-2,-2);
	queue<pair<int,pi> >Q;Q.push(mp(a,mp(b,c)));
	while(!Q.empty()){
		pair<int,pi> cur=Q.front();Q.pop();
		int vs[3]={cur.fr,cur.sc.fr,cur.sc.sc};
		int tmp[3]={vs[0],vs[1],vs[2]};
		sort(tmp,tmp+3);
		if(tmp[2]==2){
			solve(vs);
			return 0;
		}
		debug(vs,vs+3);
		REP(i,3){
			char c;
			int p,q;
			REP(j,3) REP(k,3) if(j!=i && k!=i && j!=k){
				p=vs[j];q=vs[k];
				c=g[p][q];
				prl;
			}
			dump(i);
			dump(p);dump(q);
			dump(c);
			REP(j,n) if(j!=p && j!=q && g[vs[i]][j]==c){
				int tmp=vs[i];
				vs[i]=j;
				if(back[vs[0]][vs[1]][vs[2]].fr==-1){
					dump(j);
					back[vs[0]][vs[1]][vs[2]]=mp(i,tmp);
					Q.push(mp(vs[0],mp(vs[1],vs[2])));
				}
				vs[i]=tmp;
			}
		}
	}
	printf("-1\n");


	return 0;
}