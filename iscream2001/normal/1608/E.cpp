#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=998244353;
const int N=3e5+10;
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

struct P{
	LD x,y;
	P(LD _x=0,LD _y=0){x=_x;y=_y;}
}used;

LD dis(P x){return x.x*x.x+x.y*x.y;}
P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
int n,m;
struct node{
	int x,y,c;
}a[100005],b[100005],X[100005];

bool cmpx(node x,node y){
	return x.x<y.x;
}

bool check(int ned){
	int now,www,k,hhh;
	sort(X+1,X+1+n,cmpx);
	for(int i=1;i<=3;++i){
		now=0;
		www=0;
		for(int l=now+1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&X[r+1].x==X[l].x) ++r;
			for(int o=l;o<=r;++o){
				if(X[o].c==i)++www;
			}
			now=r;
			if(www>=ned) break;
		}
		if(www>=ned){
			hhh=now;
			for(int j=1;j<=3;++j){
				if(i==j) continue;
				now=hhh;
				www=0;
				for(int l=now+1,r;l<=n;l=r+1){
					r=l;
					while(r<n&&X[r+1].x==X[l].x) ++r;
					for(int o=l;o<=r;++o){
						if(X[o].c==j)++www;
					}
					now=r;
					if(www>=ned) break;
				}
				if(www>=ned){
					k=6-i-j;www=0;
					for(int o=now+1;o<=n;++o){
						if(X[o].c==k)++www;
					}
					if(www>=ned){
						return 1;
					}
				}
			}
		}
	}
	for(int i=1;i<=3;++i){
		now=0;
		www=0;
		for(int l=now+1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&X[r+1].x==X[l].x) ++r;
			for(int o=l;o<=r;++o){
				if(X[o].c==i)++www;
			}
			now=r;
			if(www>=ned) break;
		}
		if(www>=ned){
			m=0;
			for(int o=now+1;o<=n;++o){
				b[++m]=X[o];
				swap(b[m].x,b[m].y);
			}
			if(m==0) continue;
			sort(b+1,b+1+m,cmpx);
			for(int j=1;j<=3;++j){
				if(i==j) continue;
				now=0;
				www=0;
				for(int l=now+1,r;l<=m;l=r+1){
					r=l;
					while(r<m&&b[r+1].x==b[l].x) ++r;
					for(int o=l;o<=r;++o){
						if(b[o].c==j)++www;
					}
					now=r;
					if(www>=ned) break;
				}
				if(www>=ned){
					k=6-i-j;www=0;
					for(int o=now+1;o<=m;++o){
						if(b[o].c==k)++www;
					}
					if(www>=ned){
						return 1;
					}
				}
			}
		}
	}
	for(int i=1,j=n;i<j;i++,j--) swap(X[i],X[j]);
	for(int i=1;i<=3;++i){
		now=0;
		www=0;
		for(int l=now+1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&X[r+1].x==X[l].x) ++r;
			for(int o=l;o<=r;++o){
				if(X[o].c==i)++www;
			}
			now=r;
			if(www>=ned) break;
		}
		if(www>=ned){
			m=0;
			for(int o=now+1;o<=n;++o){
				b[++m]=X[o];
				swap(b[m].x,b[m].y);
			}
			if(m==0) continue;
			sort(b+1,b+1+m,cmpx);
			for(int j=1;j<=3;++j){
				if(i==j) continue;
				now=0;
				www=0;
				for(int l=now+1,r;l<=m;l=r+1){
					r=l;
					while(r<m&&b[r+1].x==b[l].x) ++r;
					for(int o=l;o<=r;++o){
						if(b[o].c==j)++www;
					}
					now=r;
					if(www>=ned) break;
				}
				if(www>=ned){
					k=6-i-j;www=0;
					for(int o=now+1;o<=m;++o){
						if(b[o].c==k)++www;
					}
					if(www>=ned){
						return 1;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n;++i) swap(X[i].x,X[i].y);
	
	sort(X+1,X+1+n,cmpx);
	for(int i=1;i<=3;++i){
		now=0;
		www=0;
		for(int l=now+1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&X[r+1].x==X[l].x) ++r;
			for(int o=l;o<=r;++o){
				if(X[o].c==i)++www;
			}
			now=r;
			if(www>=ned) break;
		}
		if(www>=ned){
			hhh=now;
			for(int j=1;j<=3;++j){
				if(i==j) continue;
				now=hhh;
				www=0;
				for(int l=now+1,r;l<=n;l=r+1){
					r=l;
					while(r<n&&X[r+1].x==X[l].x) ++r;
					for(int o=l;o<=r;++o){
						if(X[o].c==j)++www;
					}
					now=r;
					if(www>=ned) break;
				}
				if(www>=ned){
					k=6-i-j;www=0;
					for(int o=now+1;o<=n;++o){
						if(X[o].c==k)++www;
					}
					if(www>=ned){
						return 1;
					}
				}
			}
		}
	}
	for(int i=1;i<=3;++i){
		now=0;
		www=0;
		for(int l=now+1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&X[r+1].x==X[l].x) ++r;
			for(int o=l;o<=r;++o){
				if(X[o].c==i)++www;
			}
			now=r;
			if(www>=ned) break;
		}
		if(www>=ned){
			m=0;
			for(int o=now+1;o<=n;++o){
				b[++m]=X[o];
				swap(b[m].x,b[m].y);
			}
			if(m==0) continue;
			sort(b+1,b+1+m,cmpx);
			for(int j=1;j<=3;++j){
				if(i==j) continue;
				now=0;
				www=0;
				for(int l=now+1,r;l<=m;l=r+1){
					r=l;
					while(r<m&&b[r+1].x==b[l].x) ++r;
					for(int o=l;o<=r;++o){
						if(b[o].c==j)++www;
					}
					now=r;
					if(www>=ned) break;
				}
				if(www>=ned){
					k=6-i-j;www=0;
					for(int o=now+1;o<=m;++o){
						if(b[o].c==k)++www;
					}
					if(www>=ned){
						return 1;
					}
				}
			}
		}
	}
	for(int i=1,j=n;i<j;i++,j--) swap(X[i],X[j]);
	for(int i=1;i<=3;++i){
		now=0;
		www=0;
		for(int l=now+1,r;l<=n;l=r+1){
			r=l;
			while(r<n&&X[r+1].x==X[l].x) ++r;
			for(int o=l;o<=r;++o){
				if(X[o].c==i)++www;
			}
			now=r;
			if(www>=ned) break;
		}
		if(www>=ned){
			m=0;
			for(int o=now+1;o<=n;++o){
				b[++m]=X[o];
				swap(b[m].x,b[m].y);
			}
			if(m==0) continue;
			sort(b+1,b+1+m,cmpx);
			for(int j=1;j<=3;++j){
				if(i==j) continue;
				now=0;
				www=0;
				for(int l=now+1,r;l<=m;l=r+1){
					r=l;
					while(r<m&&b[r+1].x==b[l].x) ++r;
					for(int o=l;o<=r;++o){
						if(b[o].c==j)++www;
					}
					now=r;
					if(www>=ned) break;
				}
				if(www>=ned){
					k=6-i-j;www=0;
					for(int o=now+1;o<=m;++o){
						if(b[o].c==k)++www;
					}
					if(www>=ned){
						return 1;
					}
				}
			}
		}
	}
	return 0;
	
}

void MAIN(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		X[i]=a[i];
	}
	int l=0,r=n/3,mid;
	while(l!=r){
		mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l*3);
	return;
}
//Diaspora
//flex-block
//git config --global init.defaultBranch main
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}