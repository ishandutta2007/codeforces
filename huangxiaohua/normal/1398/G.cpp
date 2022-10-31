#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int P=998244353,G=3,Gi=332748118;
const int N=2e6+5;
const int M=2e5+5;
int n,m,limit=1,L,RR[N];

ll qpow(ll a,ll n){
    ll ans=1,b=a;
    while(n){
        if(n&1) ans=(ans*b)%P;
        b=(b*b)%P;
        n>>=1;
    }
    return ans;
}
inline ll inv(ll x){return qpow(x,P-2);}
void NTT(ll *A,int type){
    for(int i=0;i<limit;i++){
        if(i<RR[i])
            swap(A[i],A[RR[i]]);
    }
    for(int mid=1;mid<limit;mid<<=1){
        ll wn=qpow(G,(P-1)/(mid*2));
        if(type==-1) wn=qpow(wn,P-2);
        for(int len=mid<<1,pos=0;pos<limit;pos+=len){
            ll w=1;
            for(int k=0;k<mid;k++,w=(w*wn)%P){
                int x=A[pos+k],y=w*A[pos+k+mid]%P;
                A[pos+k]=(x+y)%P;
                A[pos+k+mid]=(x-y+P)%P;
            }
        }
    }
    if(type==-1){
        ll limit_inv=inv(limit);
        for(int i=0;i<limit;i++)
            A[i]=A[i]*limit_inv%P;
    }
}
void polymul(ll *a,ll *b,int deg){
    for(limit=1,L=0;limit<=deg;limit<<=1) L++;
    for(int i=0;i<limit;i++) RR[i]=(RR[i>>1]>>1)|((i&1)<<(L-1));
    NTT(a,1);NTT(b,1);
    for(int i=0;i<limit;i++) a[i]=a[i]*b[i]%P;
    NTT(a,-1);
}

int a[N],f[N],x,y,i,j,k,res[N],t;
ll va[N], vb[N];
int flag[N];

int main(){
	memset(res,-1,sizeof(res));
    scanf("%d%d%d", &n,&x,&y);
    for (i=1;i<=n+1;++i) {
        scanf("%d", &a[i]);
        va[a[i]] = 1;
        vb[M-a[i]] = 1;
    }
    polymul(va, vb, 2 * M);

    for(i=M+1;i<=M*3;i++){
    	if(va[i]){f[i+i-M-M+y+y]=1;}
	}
	for(i=2;i<=N;i+=2){
		if(!f[i]){continue;}
		for(j=i;j<=N;j+=i){
			res[j]=i;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d ",res[n]);
	}
}