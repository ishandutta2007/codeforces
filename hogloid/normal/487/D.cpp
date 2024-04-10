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

int n,m,q;

char buf[100005][15];

pair<int,pi> query[100005];

const int B=100;

int mark[100005];

pi dest[100005][12];
int build(int st){
  int cnt=B,fin=q;
  CLR(mark);
  REPN(i,q,st){
    if(query[i].fr){
      mark[query[i].sc.fr]=1;
      --cnt;
      if(cnt==0){
        fin=i+1;
        break;
      }
    }
  }

  REP(i,n){
    REP(j,m) dest[i][j]=mp(i,j);
    if(!mark[i]){
      REP(j,m) if(buf[i][j]=='^'){
        dest[i][j]=(i==0?mp(i-1,j):dest[i-1][j]);
      }
      REP(j,m) if(buf[i][j]=='<'){
        dest[i][j]=(j==0?mp(i,j-1):dest[i][j-1]);
      }
      for(int j=m-1;j>=0;--j) if(buf[i][j]=='>'){
        dest[i][j]=(j==m-1?mp(i,j+1):dest[i][j+1]);
      }

      REP(j,m) if(dest[i][j].fr==i && dest[i][j].sc>=0 && dest[i][j].sc<m){
        dest[i][j]=mp(-1,-1);
      }
    }
  }
  return fin;
}

void simu(int&y,int&x,int cnt=0){
  while(1){
    ++cnt;
    if(x<0 || x>=m) return;
    if(cnt==m+2){
      x=y=-1;
      return;
    }

    if(buf[y][x]=='>') ++x;
    else if(buf[y][x]=='<') --x;
    else{
      --y;
      break;
    }
  }
}

int main(){
  cin>>n>>m>>q;
  REP(i,n) scanf("%s",buf[i]);

  REP(i,q){
    char tmp[5];
    int x,y;scanf("%s%d%d",tmp,&x,&y);
    --x;--y;
    if(tmp[0]=='A'){
      query[i]=mp(0,mp(x,y));
    }else{
      scanf("%s",tmp);
      query[i]=mp(tmp[0],mp(x,y));
    }
  }

  int fin=0;
  REP(i,q){
    if(i==fin){
      fin=build(i);
    }
    int y=query[i].sc.fr,x=query[i].sc.sc;
    if(query[i].fr==0){
      while(x>=0 && x<m && y>=0){
        if(mark[y]){
          simu(y,x);
        }else{
          pi to=dest[y][x];
          y=to.fr;
          x=to.sc;
        }
      }
      if(mp(x,y)==mp(-1,-1)) ;
      else{
        ++x;++y;
      }
      printf("%d %d\n",y,x);
    }else{
      buf[y][x]=query[i].fr;
    }
  }


      



  return 0;
}