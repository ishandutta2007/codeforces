#include <bits/stdc++.h>
using namespace std;

struct edge{
  int u,v,w,i;
};

bool operator<(edge e1,edge e2)
{
  return e1.w>e2.w;
}

int rt(int *uf,int i)
{
  return uf[i]<0?i:uf[i]=rt(uf,uf[i]);
}

void con(int *uf,int a,int b)
{
  if(a!=b){
    if(-uf[a]<-uf[b]){
      uf[a]=b;
    }
    else if(-uf[a]>-uf[b]){
      uf[b]=a;
    }
    else{
      uf[a]=b;
      uf[b]--;
    }
  }
}


int main()
{
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  static edge e[1000000];
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&(e[i].u),&(e[i].v),&(e[i].w));
    e[i].v--,e[i].u--;
    e[i].i=i;
  }
  sort(e,e+m);
  for(int t=0;t<q;t++){
    int l,r;
    scanf("%d%d",&l,&r);
    l--,r--;
    static int uf[2000];
    for(int i=0;i<2*n;i++){
      uf[i]=-1;
    }
    int ans=-1;
    for(int i=0;i<m;i++){
      if(e[i].i<l||r<e[i].i){
	continue;
      }
      int a=rt(uf,e[i].u),b=rt(uf,e[i].v),c=rt(uf,e[i].u+n),d=rt(uf,e[i].v+n);
      if(a==b||c==d){
	ans=e[i].w;
	break;
      }
      con(uf,a,d);
      con(uf,b,c);
    }
    printf("%d\n",ans);
  }
  return 0;
}