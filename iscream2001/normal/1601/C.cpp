#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=1e9+7;
const int N=1e6+10;
const LD eps=1e-8;

LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

struct jz{
	LL x[10][10];
};
jz operator * (jz A,jz B){
	jz C;
	for(int i=1;i<=6;++i){
		for(int j=1;j<=6;++j){
			C.x[i][j]=0;
		}
	}
	for(int i=1;i<=6;++i){
		for(int k=1;k<=6;++k){
			if(A.x[i][k]!=0){
				for(int j=1;j<=6;++j){
					C.x[i][j]+=A.x[i][k]*B.x[k][j];
				}
			}
		}
	}
	return C;
}
//inline char gc(){return getchar();}
bool is_pri[N+10];
LL pri[6000000];
int cntp=0;

void init_pri(){
    for(int i=2;i<=N;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
            is_pri[pri[j]*i]=1;
            if(i%pri[j]==0) {
                break;
            }
            else{
			}
        }
    }
}



struct P{
	LD x,y;
	P(LD _x=0,LD _y=0){x=_x;y=_y;}
}used;

LD dis(P x){return x.x*x.x+x.y*x.y;}
P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}

vector<LD> V[70];

LL fac[1000005],finv[1000005];
LL C(LL x,LL y){
	if(x<y) return 0;
	return fac[x]*finv[y]%M*finv[x-y]%M;
}
void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
	finv[1000000]=qpow(fac[1000000],M-2,M);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
	return;
}

int n,m;
int cnt;
int a[N],b[N],c[N+N];

int find(int x){
	int l=1,r=cnt,mid;
	while(l<=r){
//		cout<<l<<" "<<r<<" "<<x<<endl;
		mid=(l+r)>>1;
		if(c[mid]==x){
			return mid;
		}
		else if(c[mid]>x){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
//	cout<<x<<" "<<"?"<<endl;
	return l;
}

LL ANS;

void sol(int ql,int qr,int l,int r){
	if(ql>qr||l>r) return;
	if(l==r){
		for(int i=ql;i<=qr;++i){
			c[i]=l;
		}
		return;
	}
	int mid=(ql+qr)>>1;
	int mn=r-l+1,id=r,now=0;
	for(int i=l;i<=r;++i){
		if(a[i]>b[mid]){
			now++;
		}
	}
	for(int i=r;i>=l;--i){
		if(now<mn){
			mn=now;
			id=i;
		}
		if(a[i]>b[mid]) now--;
		if(b[mid]>a[i]) now++;
	}
	c[mid]=id;
	sol(ql,mid-1,l,id);
	sol(mid+1,qr,id,r);
	return;
}
int t[N+N];
void add(int x){
	while(x<=cnt){
		t[x]++;
		x+=x&-x;
	}
	return;
}
int ask(int x){
	int res=0;
	while(x>0){
		res+=t[x];
		x-=x&-x;
	}
	return res;
}
void MAIN(){
	cin>>n>>m;ANS=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];
	for(int i=1;i<=n;++i) c[i]=a[i];
	for(int i=1;i<=m;++i) c[i+n]=b[i];
	sort(c+1,c+1+n+m);
	cnt=0;
	c[0]=0;
	for(int i=1;i<=n+m;++i){
		if(c[i]!=c[i-1]){
			c[++cnt]=c[i];
		}
	}
	//for(int i=1;i<=cnt;++i) cout<<c[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i) a[i]=find(a[i]);
	for(int i=1;i<=m;++i) b[i]=find(b[i]);
	sort(b+1,b+1+m);
	//for(int i=1;i<=n;++i) cout<<a[i]<<" ";cout<<endl;
	//for(int i=1;i<=m;++i) cout<<b[i]<<" ";cout<<endl;
	a[0]=0;
	sol(1,m,0,n);
	for(int i=0;i<=cnt;++i) t[i]=0;
	for(int i=n,j=m;i>=0;--i){
		while(j>=1&&c[j]==i){
			ANS+=ask(b[j]-1);
			add(b[j]);
			j--;
		}
		if(i>0){
			ANS+=ask(a[i]-1);
			add(a[i]);
		}
	}
	cout<<ANS<<endl;
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	int ttt=1;cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
}