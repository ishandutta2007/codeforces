#include <bits/stdc++.h>
using namespace std;

template<class T> class bitsum{
 public:
  int S;
  T *bit;
  bitsum(){};
  bitsum(int BS){
    S=BS;
    bit=(T *)calloc(sizeof(T),(1<<S)+1);
  }
  bitsum(int BS,vector<T> &v){
    S=BS;
    bit=(T *)calloc(sizeof(T),(1<<S)+1);
    for(int k=0;k<=S;k++){
      for(int j=(1<<k);j<=(1<<S);j+=(1<<(k+1))){
	bit[j]=v[j-1];
	int p=j-1;
	while(p>0){
	  bit[j]+=bit[p];
	  p-=p&-p;
	}
      }
    }
  }
      
  T sum(int i)
  {
    int p=i;
    T ret=0;
    while(p>0){
      ret+=bit[p];
      p-=p&-p;
    }
    return ret;
  }
  void add(int i,T v)
  {
    int p=i+1;
    while(p<=1<<S){
      bit[p]+=v;
      p+=p&-p;
    }
  }
};


int main()
{
  int rev[256];
  rev['A']=0,rev['T']=1,rev['G']=2,rev['C']=3;
  static char S[100010];
  scanf("%s",S);
  int n=strlen(S);
  vector<bitsum<int> > bit[11][4];
  int BS[11];
  for(int md=1;md<=10;md++){
    int N=n/md+1;
    BS[md]=0;
    while((1<<BS[md])<N){
      BS[md]++;
    }
    //printf("%d\n",BS[md]);
    for(int x=0;x<4;x++){
      bit[md][x]=vector<bitsum<int> >(md);
      for(int s=0;s<md;s++){
	vector<int> tp(1<<BS[md],0);
	for(int i=0;s+i*md<n;i++){
	  tp[i]=(rev[S[s+i*md]]==x?1:0);
	}
	bit[md][x][s]=bitsum<int>(BS[md],tp);
      }
    }
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int type;
    scanf("%d",&type);
    if(type==1){
      int d;
      char c[2];
      scanf("%d%s",&d,c);
      d--;
      for(int md=1;md<=10;md++){
	int s=d%md;
	bit[md][rev[S[d]]][s].add(d/md,-1);
	bit[md][rev[c[0]]][s].add(d/md,1);
      }
      S[d]=c[0];
    }
    else{
      int l,r;
      char e[11];
      scanf("%d%d%s",&l,&r,e);
      l--;
      int md=strlen(e);
      int ans=0;
      for(int t=0;t<md&&t<r-l;t++){
	int s=(l+t)%md;
	ans+=bit[md][rev[e[t]]][s].sum((r-s+md-1)/md)-bit[md][rev[e[t]]][s].sum((l-s+md-1)/md);
	//printf("%d %d %d %d\n",(r-s+md-1)/md,(l-s+md-1)/md,bit[md][rev[e[t]]][s].sum((r-s+md-1)/md),bit[md][rev[e[t]]][s].sum((l-s+md-1)/md));
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}