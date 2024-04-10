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
int code[300];
static const int MAX_NODE=800000;
static const int CHNUM=26;
struct node{
  node* nxt[CHNUM];
  vector<int> term;
  vector<int> end;
  void init(){
    memset(nxt,0,sizeof(nxt));
  }
};
node tree[MAX_NODE];
int cnt=1;
node* root=&tree[0];
void insert(char *s,int id){
  int len=strlen(s);
  node* cur=root;
  REP(j,len){
    if(cur->nxt[code[s[j]]]==NULL){
      cur->nxt[code[s[j]]]=&tree[cnt++];
    }
    cur=cur->nxt[code[s[j]]];
  }
  cur->term.pb(id);
}
void insert2(char *s,int id){
  int len=strlen(s);
  node* cur=root;
  REP(j,len){
    if(cur->nxt[code[s[j]]]==NULL){
      cur->nxt[code[s[j]]]=&tree[cnt++];
    }
    cur=cur->nxt[code[s[j]]];
  }
  cur->end.pb(id);
}
int n;

char tmp[800005];

int ans[100005];
int tot;
void dfs(node* v,int d){
  REP(i,26){
    if(v->nxt[i]){
      dfs(v->nxt[i],d+1);
      v->term.insert(v->term.end(),ALL(v->nxt[i]->term));
      v->nxt[i]->term.clear();
      v->end.insert(v->end.end(),ALL(v->nxt[i]->end));
      v->nxt[i]->end.clear();
    }
  }
  int n=v->term.size(),m=v->end.size();
  if(n<m){
    REP(i,n) ans[v->term[i]]=v->end[m-1-i];
    v->term.clear();
    v->end.resize(m-n);
  }else{
    REP(i,m) ans[v->term[n-1-i]]=v->end[i];
    v->end.clear();
    v->term.resize(n-m);
  }
  tot+=d*min(n,m);
}
int main(){
  REP(i,26) code['a'+i]=i;

  cin>>n;
  REP(i,n){
    scanf("%s",tmp);
    insert(tmp,i);
  }
  REP(i,n){
    scanf("%s",tmp);
    insert2(tmp,i);
  }
  dfs(root,0);
  printf("%d\n",tot);
  REP(i,n) printf("%d %d\n",i+1,ans[i]+1);

  return 0;
}