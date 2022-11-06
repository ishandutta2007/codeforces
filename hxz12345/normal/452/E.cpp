#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
set<int> G;
set<int>::iterator it;
long long ans;
char S1[1001010],S2[1001010],S3[1001010];
long long MOD,tag[1001010],b[1001010],n1,n2,n3,a[1001010],L[1001010],R[1001010],w,j,now,x,up,i,lst[1001010],tn,lg[1001010],K,H[1001010],tot,n,len,B[1001010],fre[1001010],sa[1001010],rk[1001010],A[1001010],lsh[1001010],S[1001010];
void sort(int l,int r){tot=0;
	for (int i=n;i>n-len;i--) B[++tot]=i;
	for (i=1;i<=n;i++)
	    if (sa[i]>len) B[++tot]=sa[i]-len;
	for (i=1;i<=n;i++) fre[rk[B[i]]]++;
	for (i=1;i<=max(n,(long long) 5010);i++) fre[i]=fre[i-1]+fre[i];
	for (i=n;i>=1;i--) sa[fre[rk[B[i]]]--]=B[i];
	for (i=0;i<=max(n,(long long) 5010);i++) fre[i]=0;
}void Remake(){
	for (i=1;i<=n;i++) lst[i]=rk[i];tot=0;
	for (i=1;i<=n;i++)
	    if ((lst[sa[i]]==lst[sa[i-1]])&&((lst[sa[i]+len]==lst[sa[i-1]+len]))) rk[sa[i]]=tot;
	    else rk[sa[i]]=++tot;
} 
long long calc(long long l,long long r){return ((l+r)*(r-l+1)/2);}
void solve(long long val){
	len=0;
	for (i=1;i<=n;i++) S[i]=rk[i];
	S[n+1]=-1;
	sort(1,n);Remake();
for (len=1;len<=n;len<<=1) sort(1,n),Remake();K=0;
for (i=1;i<=n;i++){
	if (rk[i]==0) continue;if (K) K--;
	while ((S[sa[rk[i]]+K]==S[sa[rk[i]-1]+K])&&(K<=n)) K++;H[rk[i]]=K;
}
for (i=1;i<=n;i++) a[i]=H[i+1];n--;
    w=0;
	for (i=1;i<=n;i++){
		while ((w>0)&&(a[b[w]]>a[i])){R[b[w]]=i;w--;}
		L[i]=b[w];w++;b[w]=i;
	}while (w>0) R[b[w]]=n+1,w--;
	for (i=1;i<=n;i++){
		long long G=(MOD+val) % MOD,LL=calc(L[i]+1,i),RR=calc(i,R[i]-1);
		LL=LL % MOD;RR=RR % MOD;
		LL=LL*(R[i]-i) % MOD;LL=(-LL+MOD) % MOD;
		RR=RR*(i-L[i]) % MOD;RR=(RR+LL)*G % MOD;
		tag[a[i]]=(tag[a[i]]+RR) % MOD;		
	}
}
int main()
{MOD=1e9+7;
scanf("%s",S1+1);n1=strlen(S1+1);for (i=1;i<=n1;i++) n++,sa[n]=n,rk[n]=S1[i];n++,sa[n]=n,rk[n]=5000;
scanf("%s",S2+1);n2=strlen(S2+1);for (i=1;i<=n2;i++) n++,sa[n]=n,rk[n]=S2[i];n++,sa[n]=n,rk[n]=5001;
scanf("%s",S3+1);n3=strlen(S3+1);for (i=1;i<=n3;i++) n++,sa[n]=n,rk[n]=S3[i];
solve(1);n=0;
n=0;
for (i=1;i<=n1;i++) n++,sa[n]=n,rk[n]=S1[i];n++,sa[n]=n,rk[n]=5000;for (i=1;i<=n2;i++) n++,sa[n]=n,rk[n]=S2[i];solve(-1);
n=0;for (i=1;i<=n1;i++) n++,sa[n]=n,rk[n]=S1[i];n++,sa[n]=n,rk[n]=5000;for (i=1;i<=n3;i++) n++,sa[n]=n,rk[n]=S3[i];solve(-1);
n=0;for (i=1;i<=n2;i++) n++,sa[n]=n,rk[n]=S2[i];n++,sa[n]=n,rk[n]=5001;for (i=1;i<=n3;i++) n++,sa[n]=n,rk[n]=S3[i];solve(-1);
n=0;for (i=1;i<=n1;i++) n++,sa[n]=n,rk[n]=S1[i];solve(1);
n=0;for (i=1;i<=n2;i++) n++,sa[n]=n,rk[n]=S2[i];solve(1);
n=0;for (i=1;i<=n3;i++) n++,sa[n]=n,rk[n]=S3[i];solve(1);
n=min(n1,min(n2,n3));
for (i=n;i>=1;i--) tag[i]=(tag[i+1]+tag[i]) % MOD;
for (i=1;i<=n;i++) printf("%lld ",tag[i]);
return 0;
}