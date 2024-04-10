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
static const int MAX_N=405;
vector<int> g[MAX_N],rg[MAX_N];
int vis[MAX_N],order[MAX_N],cnt;
int group[MAX_N],gcnt;
void dfs(int v){
  vis[v]=1;
  REP(i,g[v].size()) if(!vis[g[v][i]]){
    dfs(g[v][i]);
  }
  order[cnt++]=v;
}
void rdfs(int v){
  vis[v]=1;
  group[v]=gcnt;
  REP(i,rg[v].size()) if(!vis[rg[v][i]]){
    rdfs(rg[v][i]);
  }
}

void scc(int n){
  memset(vis,0,sizeof(vis));
  cnt=gcnt=0;
  REP(i,n) if(!vis[i]){
    dfs(i);
  }
  memset(vis,0,sizeof(vis));
  for(int i=n-1;i>=0;--i) if(!vis[order[i]]){
    rdfs(order[i]);
    ++gcnt;
  }
}
char mark[30];
int n,m;
vector<pi> rule[205][2];
int conv[305];
char s[205];

int kind;
int sign[205];


bool able(const string& t){
  int m=t.size();
  REP(i,m){
    if(s[i]<t[i]) break;
    if(s[i]>t[i]) return false;
  }
  REP(i,n*2) g[i].clear(),rg[i].clear();
  REP(i,n) REP(t,2){
    for(auto e:rule[i][t]){
      int a=i+t*n,b=e.fr+e.sc*n;
      g[a].pb(b);
      rg[b].pb(a);
    }
  }
  REP(i,m){
    int c=conv[mark[t[i]-'a']];
    int a=i+(1-c)*n,b=i+c*n;
    g[a].pb(b);
    rg[b].pb(a);
  }
  scc(n*2);
  REP(i,n) if(group[i]==group[i+n]) return false;
  return true;
}
string recr(string ever){
  if(!able(ever)) return "-";
  int m=ever.size();
  if(m==n) return ever;

  bool dif=false;
  REP(i,m) if(ever[i]!=s[i]) dif=true;

  vector<int> cand;
  int done[2]={0};
  REP(c,kind){
    if(dif==false && c<s[m]-'a') continue;
    if(done[conv[mark[c]]]) continue;
    if(dif==false && c==s[m]-'a') ;
    else done[conv[mark[c]]]=1;
    cand.pb(c);
  }
  for(auto c:cand){
    string nxt=ever+((char)('a'+c));
    string tmp=recr(nxt);
    if(tmp=="-") ;
    else return tmp;
  }
  return "-";
}
int main(){
  scanf("%s",mark);
  kind=strlen(mark);
  cin>>n>>m;
  conv['V']=0;
  conv['C']=1;
  REP(i,m){
    int a,b;
    char t1[5],t2[5];
    scanf("%d%s%d%s",&a,t1,&b,t2);
    --a;--b;
    int c=conv[t1[0]],d=conv[t2[0]];
    rule[b][d^1].pb(mp(a,c^1));
    rule[a][c].pb(mp(b,d));
  }
  string res;
  scanf("%s",s);

  res=recr("");

  if(res=="-") puts("-1");
  else{
    assert(res.size()==n);
    cout<<res<<endl;
  }
  return 0;
}