#define DEB
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


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
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

//const int INF=5e8;
struct node{
	int len,link;
  map<char,int> nxt;
  bool cloned;
  int id;
};
 
const int MXLEN= 100000*11+150;
node st[MXLEN*2];
int sz, last;
 
void init(){
  REP(i,MXLEN*2) st[i].nxt.clear();
	sz=last=0;
	st[0].len=0;
	st[0].link=-1;
  ++sz;
}
 
void extend(char c,int id){
  int cur=sz++;
  st[cur].len=st[last].len+1;
  st[cur].cloned=false;
  st[cur].id=(1<<id);
	int p;
	for(p=last;~p && !st[p].nxt.count(c);p=st[p].link)
		st[p].nxt[c]=cur;
	if(p==-1)
		st[cur].link=0;
	else{
		int q=st[p].nxt[c];
		if(st[p].len+1==st[q].len)
			st[cur].link=q;
		else{
			int clone=sz++;
			st[clone].len=st[p].len+1;
      st[clone].nxt=st[q].nxt;
			st[clone].link=st[q].link;
      st[clone].cloned=true;
			for (;~p && st[p].nxt[c]==q;p=st[p].link)
				st[p].nxt[c]=clone;
			st[q].link=st[cur].link=clone ;
		}
	}
	last=cur;
}
void toposort(){
  static int idx[MXLEN*2];
  static int indeg[MXLEN*2];
  static bool vis[MXLEN*2];
  REP(i,sz) for(auto nid:st[i].nxt) ++indeg[nid.sc];

  vector<int> vlist={0};
  idx[0]=0;

  int m=1;
  REP(i,sz){
    int v=vlist[i];
    for(auto nid:st[v].nxt) if(--indeg[nid.sc]==0){
      idx[nid.sc]=m;
      vlist.pb(nid.sc);
      ++m;
//      tmp[m++]=st[nid];
    }
  }
  CLR(vis);
  REP(i,sz) if(!vis[i]){
    int cur=i;
    vector<int> cy;
    while(!vis[cur]){
      cy.pb(cur);
      vis[cur]=1;
      cur=idx[cur];
    }
    int m=cy.size();
    for(int j=m-1;j>0;--j){
      swap(st[cy[j]],st[cy[(j+1)%m]]);
    }
  }
  REP(i,sz){
    for(auto& nid:st[i].nxt) {
      nid.sc=idx[nid.sc];
    }
    st[i].link=idx[st[i].link];
  }
}
 

char s[50005];

char tmp[50005];

int dp2[1000005],dp[1000005],mark[1000005];

pi query[10];
char T[10][50005];
int len[15];
int main(){
  scanf("%s",s);
  int n=strlen(s);
  init();
  int q;
  cin>>q;
  REP(i,n) extend(s[i]-'a',q);
  extend(26,q+2);
  REP(i,q){
    int l,r;
    scanf("%s%d%d",T[i],&l,&r);
    query[i]={l,r};
    len[i]=strlen(T[i]);
    REP(j,len[i]) extend(T[i][j]-'a',i);
    extend(26,q+2);
  }
  toposort();
  lint res=0;
  dp[0]=1;
  REP(i,sz){
    for(auto e:st[i].nxt){
      dp[e.sc]+=dp[i];
    }
  }

  REP(j,q+1){
    CLR(dp2);
    for(int i=sz-1;i>=0;--i){
      if(!st[i].cloned && st[i].id>>j&1) ++dp2[i];
      if(i) dp2[st[i].link]+=dp2[i];
    }
    if(j<q){
      REP(i,sz) if(dp2[i]>=query[j].fr && dp2[i]<=query[j].sc){
        ++mark[i];
      }
    }else{
      REP(i,sz) if(dp2[i]>0 && mark[i]==q && i) res+=dp[i];
    }
  }
  cout<<res<<endl;
  return 0;
}