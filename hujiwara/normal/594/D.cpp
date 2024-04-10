#include <bits/stdc++.h>
using namespace std;
const int MN=200000,BS=18;



const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
void mn(long long &a,long long b){a+=mod-b;a%=mod;}
void ml(long long &a,long long b){a*=b;a%=mod;}

long long inv[1000001];

void prev_inv(int N)
{
  inv[0]=0;
  inv[1]=1;
  for(int i=2;i<N;i++){
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  }
}

void bitadd(long long *bit,int i,long long v)
{
  int p=i;
  while(p>0){
    ml(bit[p],v);
    p-=p&-p;
  }
}

long long bitval(long long *bit,int i)
{
  int p=i+1;
  long long ret=1ll;
  while(p<1<<BS){
    ml(ret,bit[p]);
    p+=p&-p;
  }
  return ret;
}

vector<int> prime_fac(int a)
{
  vector<int> ret;
  for(int t=2;t*t<=a;t++){
    if(a%t==0){
      ret.push_back(t);
      while(a%t==0){
	a/=t;
      }
    }
  }
  if(a>1){
    ret.push_back(a);
  }
  return ret;
}

int main()
{
  prev_inv(1000001);
  int n;
  scanf("%d",&n);
  static int a[MN];
  static vector<int> P[MN];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
    P[i]=prime_fac(a[i]);
  }
  static vector<int> F[1000001];
  for(int i=0;i<n;i++){
    for(int t=0;t<P[i].size();t++){
      int p=P[i][t];
      F[p].push_back(i);
    }
  }
  int q;
  scanf("%d",&q);
  static vector<pair<int,int> > qr[MN];
  for(int i=0;i<q;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    l--;
    qr[l].push_back(make_pair(r,i));
  }
  static long long ans[MN+1];
  ans[0]=1ll;
  for(int i=0;i<n;i++){
    ans[i+1]=ans[i];
    ml(ans[i+1],a[i]);
    for(int t=0;t<P[i].size();t++){
      int p=P[i][t];
      if(F[p][0]==i){
	ml(ans[i+1],(p-1)*inv[p]%mod);
      }
    }
    //printf("%lld\n",ans[i+1]);
  }
  static  long long bit[1<<BS];
  for(int i=1;i<1<<BS;i++){
    bit[i]=1ll;
  }
  static long long ret[MN];
  static long long T[1000001]={0};
  for(int i=0;i<n;i++){
    for(int t=0;t<qr[i].size();t++){
      int r=qr[i][t].first;
      ret[qr[i][t].second]=ans[r]*bitval(bit,r)%mod;
      //printf("%d %d %d %lld %lld\n",i+1,qr[i][t].first,qr[i][t].second,ans[r],bitval(bit,r));
    }
    bitadd(bit,n+1,inv[a[i]]);
    for(int t=0;t<P[i].size();t++){
      int p=P[i][t];
      T[p]++;
      bitadd(bit,T[p]==F[p].size()?n+1:F[p][T[p]]+1,p*inv[p-1]%mod);
      //printf("%d %d %lld\n",i+1,p,T[p]==F[p].size()?n:F[p][T[p]]);
    }
  }
  for(int i=0;i<q;i++){
    printf("%lld\n",ret[i]);
  }
  return 0;
}