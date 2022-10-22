#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=1e6+10;
int n;

int ptt,pri[maxn];
void sieve(){
  ptt=0;
  memset(pri,0,(n+1)<<2);
  rep(i,2,n){
    if(!pri[i])pri[++ptt]=i;
    rep(j,1,ptt){
      int x=i*pri[j];
      if(x>n)break;
      pri[x]=1;
      if(i%pri[j]==0)break;
    }
  }
}

void solve(){
//  static int tmp=505;
//  n=(tmp+=2);
//  printf("(%d)\n",n);
//  n=5e5;
  cin>>n;
  if(n<=11){
    int mx=0;
    rep(_S,0,(1<<n)-1){
      int S=_S<<1;
      ll v=1;
      rep(i,1,n){
        if(S>>i&1){
          rep(j,1,i){
            v*=j;
            rep(t,2,n)while(v%(t*t)==0)v/=t*t;
          }
        }
      }
      ll tp=sqrt(v);
      if(tp*tp==v){
        chkmax(mx,__builtin_popcount(S));
      }
    }
    printf("%d\n",mx);
//    printf("#%d : %d\n",n,mx);
    rep(_S,0,(1<<n)-1){
      int S=_S<<1;
      ll v=1;
      rep(i,1,n){
        if(S>>i&1){
          rep(j,1,i){
            v*=j;
            rep(t,2,n)while(v%(t*t)==0)v/=t*t;
          }
        }
      }
      ll tp=sqrt(v);
      if(tp*tp==v&&mx==__builtin_popcount(S)){
        rep(i,1,n)if(S>>i&1)printf("%d ",i);
        puts("");
        return;
      }
    }
    return;
  }
  static bool goal[maxn];
//  if(n&1){
//    bool asf=1;
//    sieve();
//    rep(i,1,ptt){
//      int p=pri[i];
//      ll ct=0;
//      int t=1;
//      while(1){
//        if(1ll*t*p>n)break;
//        t*=p;
//        int tp=n/t;
//  //      rep(i,1,tp-1)ct+=t*i;
//        ct+=1ll*(tp-1)*tp/2*t;
//        ct&=1;
//  //      rep(i,tp*t,n)ct+=i/t;
//        ct+=1ll*(n-tp*t+1)*tp;
//        ct&=1;
//  //      rep(x,1,n)ct+=x/t;
//      }
//      goal[i]=ct&1;
//      asf&=goal[i]==0;
////      printf("(p %d) : %lld\n",p,ct);
//    }
//    if(asf){
//      printf("%d\n",n);
//      rep(i,1,n)printf("%d ",i);
//      exit(0);
//      return;
//    }
//    vi vec(n);
//    rep(i,1,n)vec[i-1]=i;
//    rep(_,1,ptt){
//      if(vec.size()<=0u)break;
//      vi ano;
//      ano.reserve(vec.size());
//      int p=pri[_];
//      for(int x:vec){
//        int t=1,ct=0;
//        while(1){
//          if(1ll*t*p>x)break;
//          t*=p;
//          ct+=x/t;
//        }
////        printf("%d (p %d) : %d\n",x,p,ct);
//        if((ct&1)==goal[_]){
//          ano.push_back(x);
//        }
//      }
//      vec.swap(ano);
//    }
////    if(vec.empty()){
////      goto GG;
////    }
//    if(vec.empty()){
//      if(n>1000){
//        goal[1]^=1;
//        vi vec;
//        vec.reserve(n);
//        rep(i,3,n)vec.push_back(i);
//        rep(_,1,ptt){
//          if(vec.empty())break;
//          vi ano;
//          ano.reserve(vec.size());
//          int p=pri[_];
//          for(int x:vec){
//            int t=1,ct=0;
//            while(1){
//              if(1ll*t*p>x)break;
//              t*=p;
//              ct+=x/t;
//            }
//      //      printf("%d (p %d) : %d\n",x,p,ct);
//            if((ct&1)==goal[_]){
//              ano.push_back(x);
//            }
//          }
//          vec.swap(ano);
//        }
//        if(vec.empty()){
//  //        exit(0);
//          goto GG;
//        }
//        int ans1=2,ans2=vec[0];
//        printf("%d\n",n-2);
//        rep(i,1,n)if(i!=ans1&&i!=ans2)printf("%d ",i);
//        exit(0);
//        return;
//      }else{
////        goto GG;
//        rep(i,2,n){
//          rep(j,i+1,n){
//            bool flg=1;
//            rep(_,1,ptt){
//              int p=pri[_];
//              int t=1,ct=0;
//              while(1){
//                if(1ll*t*p>n)break;
//                t*=p;
//                ct+=i/t+j/t;
//              }
//              if((ct&1)!=goal[_]){
//                flg=0;break;
//              }
//            }
//            if(flg){
//              printf("%d\n",n-2);
//              rep(k,1,n)if(i!=k&&j!=k)printf("%d ",k);
//              return;
//            }
//          }
//        }
//        goto GG;
//      }
//    }
//  //  printf("#%d\n",n);
//  //  printf("#%d\n",vec[0]);
//    int ans=vec[0];
//    printf("%d\n",n-1);
//    rep(i,1,n)if(ans!=i)printf("%d ",i);
//    ll res=1;
//    rep(i,1,n)if(ans!=i){
//      rep(j,1,i){
//        res*=j;
//        rep(k,1,n)if(res%(k*k)==0)res/=(k*k);
//      }
//    }
//    cout<<res;
//    exit(0);
//    return;
//  }
//  GG:
  sieve();
  memset(goal,0,sizeof goal);
  bool odd=n&1;
  n-=odd;
  bool asf=1;
  rep(i,1,ptt){
    int p=pri[i];
    ll ct=0;
    int t=1;
    while(1){
      if(1ll*t*p>n)break;
      t*=p;
      int tp=n/t;
//      rep(i,1,tp-1)ct+=t*i;
      ct+=1ll*(tp-1)*tp/2*t;
      ct&=1;
//      rep(i,tp*t,n)ct+=i/t;
      ct+=1ll*(n-tp*t+1)*tp;
      ct&=1;
//      rep(x,1,n)ct+=x/t;
    }
    goal[i]=ct&1;
    asf&=goal[i]==0;
//    printf("(p %d) : %d\n",p,ct);
  }
  if(asf){
    printf("%d\n",n);
    rep(i,1,n)printf("%d ",i);
    return;
  }
  vi vec(n);
  rep(i,1,n)vec[i-1]=i;
  rep(_,1,ptt){
    if(vec.size()<=0u)break;
    vi ano;
    ano.reserve(vec.size());
    int p=pri[_];
    for(int x:vec){
      int t=1,ct=0;
      while(1){
        if(1ll*t*p>x)break;
        t*=p;
        ct+=x/t;
      }
//      printf("%d (p %d) : %d\n",x,p,ct);
      if((ct&1)==goal[_]){
        ano.push_back(x);
      }
    }
    vec.swap(ano);
  }
  static bool YELL[maxn];
  memcpy(YELL,goal,sizeof goal);
  if(vec.empty()){
    if(odd){
      n++;
      rep(_,1,ptt){
        int p=pri[_];
        int t=1,ct=0;
        while(1ll*t*p<=n){
          t*=p,ct+=n/t;
        }
        goal[_]^=ct&1;
      }
      vector<vi>arr;
      vi ini(n-2);
      rep(i,2,n)ini[i-2]=i;
      arr.push_back(ini);
      rep(_,1,ptt)if(!goal[_]){
//        printf("#%d\n",_);
        vector<vi>tmp;
        int p=pri[_];
        for(vi&V:arr){
//          printf("%d ",(int)vec.size());
          vi buk[2];
          for(int x:V){
            int t=1,ct=0;
            while(1ll*t*p<=x){
              t*=p,ct+=x/t;
            }
//            printf("(x %d) (p %d) : %d\n",x,p,ct);
            buk[ct&1].push_back(x);
          }
          rep(t,0,1)if(buk[t].size()>1u){
            if(buk[t].size()<=10u){
              vi&vec=buk[t];
              rep($1,0,vec.size()-1)rep($2,$1+1,vec.size()-1){
                bool flg=1;
                int x=vec[$1],y=vec[$2];
      //          printf("(%d %d)\n",x,y);
                rep($,1,ptt)if(goal[$]){
                  int p=pri[$],t=1,ct=0;
                  while(1ll*t*p<=n){
                    t*=p,ct+=x/t+y/t;
                  }
                  if(ct%2==0){
                    flg=0;break;
                  }
                }
                if(flg){
                  rep($,_+1,ptt)if(!goal[$]){
                    int p=pri[$];
                    int t=1,ct=0;
                    while(1ll*t*p<=n){
                      t*=p,ct+=x/t+y/t;
                    }
                    if(ct%2==1){
                      flg=0;break;
                    }
                  }
                }
                if(flg){
                  printf("%d\n",n-2);
                  rep(i,1,n)if(i!=x&&i!=y)printf("%d ",i);
      //            ll res=1;
      //            rep(i,1,n)if(i!=x&&i!=y)rep(j,1,i){
      //              res*=j;rep(k,2,n)while(res%(k*k)==0)res/=k*k;
      //            }
      //            cout<<res<<endl;
                  exit(0);
                  return;
                }
              }
            }else{
              tmp.push_back(buk[t]);
            }
          }
        }
        arr.swap(tmp);
//        puts("");
      }
      n--;
      goto qwq;
    }
    qwq:
    memcpy(goal,YELL,sizeof YELL);
    goal[1]^=1;
    vi vec;
    vec.reserve(n);
    rep(i,3,n)vec.push_back(i);
    rep(_,1,ptt){
      if(vec.size()<=0u)break;
      vi ano;
      ano.reserve(vec.size());
      int p=pri[_];
      for(int x:vec){
        int t=1,ct=0;
        while(1){
          if(1ll*t*p>x)break;
          t*=p;
          ct+=x/t;
        }
  //      printf("%d (p %d) : %d\n",x,p,ct);
        if((ct&1)==goal[_]){
          ano.push_back(x);
        }
      }
      vec.swap(ano);
    }
    if(vec.empty()&&0){
      goal[1]^=1;
      vector<vi>arr;
      vi ini(n-2);
      rep(i,2,n)ini[i-2]=i;
      arr.push_back(ini);
      rep(_,1,ptt)if(!goal[_]){
//        printf("#%d\n",_);
        vector<vi>tmp;
        int p=pri[_];
        for(vi&V:arr){
//          printf("%d ",(int)vec.size());
          vi buk[2];
          for(int x:V){
            int t=1,ct=0;
            while(1ll*t*p<=x){
              t*=p,ct+=x/t;
            }
//            printf("(x %d) (p %d) : %d\n",x,p,ct);
            buk[ct&1].push_back(x);
          }
          rep(t,0,1)if(buk[t].size()>1u){
            if(buk[t].size()<=10u){
              vi&vec=buk[t];
              rep($1,0,vec.size()-1)rep($2,$1+1,vec.size()-1){
                bool flg=1;
                int x=vec[$1],y=vec[$2];
      //          printf("(%d %d)\n",x,y);
                rep($,1,ptt)if(goal[$]){
                  int p=pri[$],t=1,ct=0;
                  while(1ll*t*p<=n){
                    t*=p,ct+=x/t+y/t;
                  }
                  if(ct%2==0){
                    flg=0;break;
                  }
                }
                if(flg){
                  rep($,_+1,ptt)if(!goal[$]){
                    int p=pri[$];
                    int t=1,ct=0;
                    while(1ll*t*p<=n){
                      t*=p,ct+=x/t+y/t;
                    }
                    if(ct%2==1){
                      flg=0;break;
                    }
                  }
                }
                if(flg){
                  printf("%d\n",n-2);
                  rep(i,1,n)if(i!=x&&i!=y)printf("%d ",i);
      //            ll res=1;
      //            rep(i,1,n)if(i!=x&&i!=y)rep(j,1,i){
      //              res*=j;rep(k,2,n)while(res%(k*k)==0)res/=k*k;
      //            }
      //            cout<<res<<endl;
                  exit(0);
                  return;
                }
              }
            }else{
              tmp.push_back(buk[t]);
            }
          }
        }
        arr.swap(tmp);
//        puts("");
      }
      exit(0);
      return;
    }
    assert(!vec.empty());
    int ans1=2,ans2=vec[0];
    printf("%d\n",n-2);
    rep(i,1,n)if(i!=ans1&&i!=ans2)printf("%d ",i);
    return;
//    rep(i,2,n){
//      rep(j,i+1,n){
//        bool flg=1;
//        rep(_,1,ptt){
//          int p=pri[_];
//          int t=1,ct=0;
//          while(1){
//            if(1ll*t*p>n)break;
//            t*=p;
//            ct+=i/t+j/t;
//          }
//          if((ct&1)!=goal[_]){
//            flg=0;break;
//          }
//        }
//        if(flg){
//          printf("%d\n",n-2);
//          rep(k,1,n)if(i!=k&&j!=k)printf("%d ",k);
//          return;
//        }
//      }
//    }
  }
//  printf("#%d\n",n);
//  printf("#%d\n",vec[0]);
  assert(!vec.empty());
  int ans=vec[0];
  printf("%d\n",n-1);
  bool flg=0;
  rep(i,1,n)if(ans!=i)printf("%d ",i);else flg=1;
  assert(flg);
}

signed main(){
//  while(1)solve();
  solve();
  orzjk::flush();
  return 0;
}