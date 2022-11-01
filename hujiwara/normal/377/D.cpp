#include <cstdio>
#include <algorithm>
using namespace std;

void segadd(int seg1[1<<20],int seg2[1<<20],int seg3[1<<20],int i,int j,int k,int a,int b,int c)
{
  if(a<=j&&k<=b){
    seg1[i]+=c;
    seg2[i]+=c;
  }
  else if(!(b<=j||k<=a)){
    segadd(seg1,seg2,seg3,2*i+1,j,(j+k)/2,a,b,c);
    segadd(seg1,seg2,seg3,2*i+2,(j+k)/2,k,a,b,c);
    int k1=seg1[2*i+1],k2=seg1[2*i+2];
    if(k1>=k2){
      seg1[i]=k1+seg2[i];
      seg3[i]=seg3[2*i+1];
    }
    else{
      seg1[i]=k2+seg2[i];
      seg3[i]=seg3[2*i+2];
    }
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  static int L[100000],V[100000],R[100000];
  static pair<int,int> P[100000],X[100000];
  for(int i=0;i<n;i++){
    //scanf("%d%d%d",&(P[i].first.first),&(P[i].second.first),&(P[i].second.second));
    scanf("%d%d%d",L+i,V+i,R+i);
    P[i].first=L[i];
    P[i].second=i;
    X[i].first=V[i];
    X[i].second=i;
  }
  sort(P,P+n);
  sort(X,X+n);
  static int seg1[1<<20]={0},seg2[1<<20]={0},seg3[1<<20]={0};
  for(int i=0;i<1<<19;i++){
    seg3[i+(1<<19)-1]=i;
  }
  for(int i=(1<<19)-2;i>=0;i--){
    seg3[i]=seg3[2*i+1];
  }
  int M=-1,mL,mV;
  for(int i=0,j=0;i<n;){
    int k1=P[i].first,k2=X[j].first;
    if(k1<=k2){
      int l=P[i].second;
      //printf("%d %d %d\n",i,j,l);
      segadd(seg1,seg2,seg3,0,0,1<<19,V[l],R[l]+1,1);
      int p=seg1[0],q=seg3[0];
      //printf("%d %d\n",p,q);
      if(M<p){
	M=p;
	mL=P[i].first;
	mV=q;
      }
      i++;
    }
    else{
      int l=X[j].second;
      segadd(seg1,seg2,seg3,0,0,1<<19,V[l],R[l]+1,-1);
      j++;
    }
  }
  printf("%d\n",M);
  for(int i=0;i<n;i++){
    if(L[i]<=mL&&mL<=V[i]&&V[i]<=mV&&mV<=R[i]){
      printf("%d ",i+1);
    }
  }
  putchar('\n');
  return 0;
}