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

const int CHNUM=26;
struct node{
	int len,link;
  int nxt[CHNUM];
  bool cloned;
};
 
const int MXLEN=1000005;
node st[MXLEN*2];
int sz, last;
 
void init(){
  REP(i,MXLEN*2) memset(st[i].nxt,-1,sizeof(st[i].nxt));
	sz=last=0;
	st[0].len=0;
	st[0].link=-1;
  ++sz;
}
 
void extend(int c){
  int cur=sz++;
  st[cur].len=st[last].len+1;
  st[cur].cloned=false;
	int p;
	for(p=last;~p && st[p].nxt[c]==-1;p=st[p].link)
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
      REP(i,CHNUM) st[clone].nxt[i]=st[q].nxt[i];
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
  static node tmp[MXLEN*2];
  int m=0;

  REP(i,sz) for(auto nid:st[i].nxt) if(~nid) ++indeg[nid];

  tmp[m++]=st[0];
  idx[0]=0;
  REP(i,sz){
    for(auto nid:tmp[i].nxt) if(~nid && --indeg[nid]==0){
      idx[nid]=m;
      tmp[m++]=st[nid];
    }
  }
  REP(i,sz){
    for(auto& nid:tmp[i].nxt) if(~nid){
      nid=idx[nid];
    }
    tmp[i].link=idx[tmp[i].link];
  }
  REP(i,sz) st[i]=tmp[i];
}

char s[1000005],tmp[1000005];

int n;
lint dp[2000005];

int shift[1000005];
void maketable(char* s,int* table){
  int n=strlen(s);
  table[0]=0;
  for(int i=1;i<=n;++i){
    int j=table[i-1];
    while(j>0 && s[j]!=s[i]) j=table[j-1];
    if(s[j]==s[i]) ++j;
    table[i]=j;
  }
}


int main(){
  scanf("%s",s);
  int m=strlen(s);
  init();
  REP(i,m) extend(s[i]-'a');
  toposort();
  for(int i=sz-1;i>=0;--i){
    if(!st[i].cloned) dp[i]++;
    if(i) dp[st[i].link]+=dp[i];
  }
  cin>>n;
  REP(i,n){
    scanf("%s",tmp);
    int m2=strlen(tmp);
    maketable(tmp,shift);
    dump(shift[m2-1]);
    int pr=m2-shift[m2-1];
    if(m2%pr==0) pr=pr-1;
    else pr=m2-1;
    int cur=0,len=0;
    lint res=0;
    dump(pr);
    REP(j,m2+pr){
      int c=tmp[j%m2]-'a';
      while(cur>0 && st[cur].nxt[c]==-1){
        cur=st[cur].link;
        len=st[cur].len;
      }
      if(~st[cur].nxt[c]){
        cur=st[cur].nxt[c];
        ++len;
      }
      while(st[st[cur].link].len>=m2){
        cur=st[cur].link;
        len=st[cur].len;
      }
      if(len>=m2) res+=dp[cur];
      dump(res);dump(cur);dump(st[cur].len);dump(dp[cur]);
    }
    cout<<res<<endl;
  }
  return 0;
}