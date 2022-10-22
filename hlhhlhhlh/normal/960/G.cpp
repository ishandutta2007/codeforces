// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=400010;
const int mod=998244353;
int i,j,k;
int n,a,aa,nn;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
/*
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			x=x-t1; t3=(t3*t2)%mod;
		}
		t1=t1*2; t2=(t2*t2)%mod;
	}
	return t3;
}
long long inv[maxn],ni[maxn];
long long C(long long n,long long m){
	return (((inv[n]*ni[m])%mod)*ni[n-m])%mod;
}
long long r[maxn];
void NTT(long long *A,long long n,long long fla){
	long long i,j,k,mx=1,l=0,Wn,w,x,y;
	while (mx<n){ mx=mx*2; l++; }
	for (i=0;i<mx;i++) r[i]=(r[i/2]/2)+((i&1)<<(l-1));
	for (i=0;i<mx;i++) if (i<r[i]) swap(A[i],A[r[i]]);
	for (i=1;i<mx;i=i*2){
		if (fla==1) Wn=getax(3,(mod-1)/i/2); else Wn=getax(3,(mod-1)-(mod-1)/i/2);
		for (j=0;j<mx;j=j+i*2){
			for (k=0,w=1;k<i;k++,w=(w*Wn)%mod){
				x=A[j+k]; y=(w*A[j+k+i])%mod;
//				A[j+k]=(x+y)%mod; A[j+k+i]=(x-y+mod)%mod;
				A[j+k]=((x+y<mod)?(x+y):(x+y-mod));
				A[j+k+i]=((x-y>=0)?(x-y):(x-y+mod));
			}
		}
	}
}

long long A[maxn];
void work(int n){
	if (n==1){
		a[1]=1;
		return;
	}
	work(n/2);
	for (i=1;i<=n/2;i++){
		A[i]=a[i]*inv[i];
		B[i]=(B[i-1]*(n/2)%mod*inv[i-j-1]%mod*ni[i-j])%mod;
	}
	for (i=1;i<=n;i++){
		
	}
}
*/
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			x=x-t1; t3=(t3*t2)%mod;
		}
		t1=t1*2; t2=(t2*t2)%mod;
	}
	return t3;
}
long long inv[maxn],ni[maxn];
long long C(long long n,long long m){
	if (n<m) return 0;
	return (((inv[n]*ni[m])%mod)*ni[n-m])%mod;
}
long long r[maxn];
long long b[maxn],c[maxn],d[maxn],mx,nii;
long long B[maxn];
void NTT(long long *A,long long n,long long fla){
	long long i,j,k,mx=1,l=0,Wn,w,x,y;
	while (mx<n){ mx=mx*2; l++; }
	for (i=0;i<mx;i++) r[i]=(r[i/2]/2)+((i&1)<<(l-1));
	for (i=0;i<mx;i++) if (i<r[i]) swap(A[i],A[r[i]]);
	for (i=1;i<mx;i=i*2){
		if (fla==1) Wn=getax(3,(mod-1)/i/2); else Wn=getax(3,(mod-1)-(mod-1)/i/2);
		for (j=0;j<mx;j=j+i*2){
			for (k=0,w=1;k<i;k++,w=(w*Wn)%mod){
				x=A[j+k]; y=(w*A[j+k+i])%mod;
//				A[j+k]=(x+y)%mod; A[j+k+i]=(x-y+mod)%mod;
				A[j+k]=((x+y<mod)?(x+y):(x+y-mod));
				A[j+k+i]=((x-y>=0)?(x-y):(x-y+mod));
			}
		}
	}
}
void work(long long *A,int l,int r,int ll,int rr,int fla){
	int i,len,mx; long long nii;
	
	if (fla==1){
		for (i=0;i<=r-l;i++) b[i]=A[i+l]; b[r-l+1]=1;
		for (i=0;i<=rr-ll;i++) c[i]=A[i+ll]; c[rr-ll+1]=1;
	}
	len=(r-l+2)+(rr-ll+2);
		
	NTT(b,len,1);
	NTT(c,len,1);
	mx=1; while (mx<len) mx=mx*2;
	for (i=0;i<mx;i++) d[i]=(b[i]*c[i])%mod;
	NTT(d,len,-1);
	 
	nii=getax(mx,mod-2);
	for (i=l;i<=rr;i++){
		A[i]=(d[i-l]*nii)%mod;
	}
	
	for (i=0;i<mx;i++) b[i]=0;
	for (i=0;i<mx;i++) c[i]=0;
		
	return;
}

void CDQ_NTT(long long *A,long long l,long long r,long long fla){
	if (l==r){
		A[l]=l;
		return;
	}
	long long mid=(l+r)>>1;
	CDQ_NTT(A,l,mid,fla);
	CDQ_NTT(A,mid+1,r,fla);
	work(A,l,mid,mid+1,r,fla);
}

int main(){
	n=read(); a=read(); aa=read();
	if ((a==0)||(aa==0)){
		printf("0\n"); return 0;
	}
	if (n==1){
		if ((a==1)&&(aa==1)){
			printf("1\n"); return 0;
		}
		else{
			printf("0\n"); return 0;
		}
	}
	if ((a==1)&&(aa==1)){
		printf("0\n"); return 0;
	}
	inv[0]=1; for (i=1;i<=n;i++) inv[i]=(inv[i-1]*i)%mod;
	ni[n]=getax(inv[n],mod-2); for (i=n-1;i>=0;i--) ni[i]=(ni[i+1]*(i+1))%mod;
	
	CDQ_NTT(B,0,n-2,1); B[n-1]=1;
	
	printf("%lld\n",B[a+aa-2]*C(a+aa-2,a-1)%mod);
	
	return 0;
}