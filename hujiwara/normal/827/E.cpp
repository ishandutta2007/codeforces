#include <bits/stdc++.h>

using namespace std;
const double Pi=asin(1.)*2;
void FFT(int r,complex<double> *a,complex<double> *f,bool inv)
{
  complex<double> Z[30];
  Z[r]=complex<double>(cos(2*Pi/(1<<r)),(inv?1:-1)*sin(2*Pi/(1<<r)));
  for(int i=r-1;i>0;i--){
    Z[i]=Z[i+1]*Z[i+1];
  }
  for(int i=0;i<1<<r;i++){
    int j=0;
    for(int x=0;x<r;x++){
      if((i>>x)&1){
	j|=1<<(r-x-1);
      }
    }
    f[i]=a[j];
  }
  for(int t=1;t<=r;t++){
    for(int i=0;i<1<<r;i+=1<<t){
      complex<double> z=1;
      for(int j=i;j<i+(1<<(t-1));j++){
	int k=j+(1<<(t-1));
	complex<double> t0=f[j],t1=z*f[k];
	f[j]=t0+t1;
	f[k]=t0-t1;
	z*=Z[t];
      }
    }
  }
  if(inv){
    for(int i=0;i<1<<r;i++){
      f[i]/=(1<<r);
    }
  }
}
complex<double> temp1[1<<20],temp2[1<<20];
void conv(int r,complex<double> *A,complex<double> *B,complex<double> *C)
{
  FFT(r,A,temp1,0);
  FFT(r,B,temp2,0);
  for(int i=0;i<1<<r;i++){
    temp1[i]*=temp2[i];
  }
  FFT(r,temp1,C,1);
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--){
    int n;
    scanf("%d",&n);
    static char s[500010];
    scanf("%s",s);
    int BS=0;
    while((1<<BS)<2*n+10){
      BS++;
    }
    static complex<double> A[1<<20],B[1<<20],C[1<<20];
    for(int i=0;i<1<<BS;i++){
      if(i<n&&s[i]=='V'){
	A[i]=1.;
      }
      else{
	A[i]=0.;
      }
      if(i<n&&s[n-i-1]=='K'){
	B[i]=1.;
      }
      else{
	B[i]=0.;
      }
    }
    conv(BS,A,B,C);
    static bool c[1000000];
    for(int i=0;i<2*n;i++){
      c[i]=(C[i].real()>0.5);
    }
    static bool d[500010];
    int ct=0;
    for(int i=1;i<=n;i++){
      d[i]=1;
      for(int j=1;i*j<n;j++){
	if(c[n-1-i*j]||c[n-1+i*j]){
	  d[i]=0;
	  break;
	}
      }
      if(d[i]){
	ct++;
      }
    }
    printf("%d\n",ct);
    for(int i=1;i<=n;i++){
      if(d[i]){
	printf("%d ",i);
      }
    }
    putchar('\n');
  }
  return 0;
}