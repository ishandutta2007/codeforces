#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}
long long sq(long long a){return a*a%mod;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%mod;
}
long long inv(long long a){return pw(a,mod-2);}

void euler_tour(int i,int *N,int *M,int &t,vector<vector<int> > &e)
{
  N[i]=t;
  t++;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    euler_tour(j,N,M,t,e);
  }
  M[i]=t;
}


void segmul(long long *segp,long long *segs,int i,int j,int k,int a,int b,long long v)
{
  if(a<=j&&k<=b){
    ml(segp[i],v);
    ml(segs[i],v);
    //printf("%d %d %d %lld %lld %lld\n",i,j,k,segp[i],segs[i],v);
  }
  else if(a<k&&j<b){
    segmul(segp,segs,2*i,j,(j+k)/2,a,b,v);
    segmul(segp,segs,2*i+1,(j+k)/2,k,a,b,v);
    segs[i]=(segs[2*i]+segs[2*i+1])%mod*segp[i]%mod;
  }
}

void segadd(long long *segp,long long *segs,int i,long long d)
{
  int p=i+(1<<18);
  while(p>0){
    ml(d,segp[p]);
    ad(segs[p],d);
    //printf("%d %lld %lld\n",i,d,segs[p]);
    p/=2;
  }
}

long long segsum(long long *segp,long long *segs,int i,int j,int k,int a,int b)
{
  long long ret;
  if(a<=j&&k<=b){
    ret=segs[i];
  }
  else if(a<k&&j<b){
    ret=(segsum(segp,segs,2*i,j,(j+k)/2,a,b)+segsum(segp,segs,2*i+1,(j+k)/2,k,a,b))%mod;
    ml(ret,segp[i]);
  }
  else{
    ret=0;
  }
  return ret;
}

long long segpval(long long *segp,int i)
{
  int p=i+(1<<18);
  long long ret=1;
  while(p>0){
    ml(ret,segp[p]);
    p/=2;
  }
  return ret;
}

int main()
{
  int q;
  vector<long long> v;
  long long V;
  scanf("%lld%d",&V,&q);
  v.push_back(V);
  static int Tp[200000];
  vector<int> p;
  p.push_back(0);
  vector<int> u;
  for(int i=0;i<q;i++){
    scanf("%d",Tp+i);
    if(Tp[i]==1){
      int P;
      long long V;
      scanf("%d%lld",&P,&V);
      P--;
      v.push_back(V);
      p.push_back(P);
    }
    else{
      int U;
      scanf("%d",&U);
      U--;
      u.push_back(U);
    }
  }
  int n=v.size();
  vector<vector<int> > e(n);
  for(int i=1;i<n;i++){
    e[p[i]].push_back(i);
  }
  static int A[200000],B[200000],T=0;
  euler_tour(0,A,B,T,e);
  static long long segp[1<<19],segs[1<<19];
  for(int i=1;i<1<<19;i++){
    segp[i]=1;
    segs[i]=0;
  }
  segadd(segp,segs,A[0],v[0]);
  static int D[200000];
  for(int i=0;i<n;i++){
    D[i]=1;
  }
  for(int t=0,i=1,j=0;t<q;t++){
    if(Tp[t]==1){
      int k=p[i];
      segmul(segp,segs,1,0,1<<18,A[k],B[k],(D[k]+1)*inv(D[k])%mod);
      D[k]++;
      segadd(segp,segs,A[i],v[i]);
      //printf("%d %d\n",A[i],B[i]);
      i++;
    }
    else{
      int k=u[j];
      long long ans=segsum(segp,segs,1,0,1<<18,A[k],B[k]);
      long long vp=segpval(segp,A[k])*inv(D[k])%mod;
      printf("%lld\n",ans*inv(vp)%mod);
      j++;
    }
  }
  return 0;
}