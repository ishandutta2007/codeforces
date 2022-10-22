#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const LD PI=acos(-1.0);
const LL M=1e9+7;
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
char s[200];

int to[20][300][2];

int f[150][3000];
pair<int,int> fa[150][3000];
void PUTANS(pair<int,int> tmp){
	if(tmp.first==0&&tmp.second==0) return;
	pair<int,int> par=fa[tmp.first][tmp.second];
	PUTANS(par);
	putchar(tmp.first);
	return; 
}
void MAIN(){
	memset(to,0,sizeof(to));
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%s",s+1);
		m=strlen(s+1);
		for(int j=1;j<=m;++j){
			if(to[i][s[j]][0]==0){
				to[i][s[j]][0]=j;
			}
			else{
				to[i][s[j]][1]=j;
			}
		}
	}
	int nc,np,fl,sss,now;
	pair<int,int> ans=make_pair(0,0);
	for(int o=1;o<=m;++o){
		nc=s[o];
		fl=0;
		for(int i=0;i<n;++i){
			if(to[i][nc][0]==0) fl=1;
		}
		if(fl==0){
		//	cout<<"?"<<endl;
			f[nc][0]=1;
			fa[nc][0]=make_pair(0,0);
			ans=make_pair(nc,0);
		}
	}
	
	for(int o=1;o<=m;++o){
		nc=s[o];
		if(o==to[n-1][nc][0]){
			np=0;
		}
		else np=(1<<(n-1));
		for(int S=np;S<(1<<(n-1))+np;++S){
			if(f[nc][S]>0){
			//	cout<<nc<<" "<<S<<endl;
				if(f[nc][S]>f[ans.first][ans.second]){
					ans=make_pair(nc,S);
				}
				for(int ccc='a';ccc<='z';++ccc){
					fl=0;sss=0;
					for(int i=0;i<n;++i){
						now=(S&(1<<i));
						if(now>0) now=1;
						if(to[i][ccc][0]!=0&&to[i][ccc][0]>to[i][nc][now]){
							sss=sss;
						}
						else if(to[i][ccc][1]!=0&&to[i][ccc][1]>to[i][nc][now]){
							sss^=(1<<i);
						}
						else{
							fl=1;
							break;
						}
					}
					if(fl==0){
						if(f[nc][S]+1>f[ccc][sss]){
							f[ccc][sss]=f[nc][S]+1;
							fa[ccc][sss]=make_pair(nc,S);
						}
					}
				}
				for(int ccc='A';ccc<='Z';++ccc){
					fl=0;sss=0;
					for(int i=0;i<n;++i){
						now=(S&(1<<i));
						if(now>0) now=1;
						if(to[i][ccc][0]!=0&&to[i][ccc][0]>to[i][nc][now]){
							sss=sss;
						}
						else if(to[i][ccc][1]!=0&&to[i][ccc][1]>to[i][nc][now]){
							sss^=(1<<i);
						}
						else{
							fl=1;
							break;
						}
					}
					if(fl==0){
						if(f[nc][S]+1>f[ccc][sss]){
							f[ccc][sss]=f[nc][S]+1;
							fa[ccc][sss]=make_pair(nc,S);
						}
					}
				}
			}
		}
	}
	printf("%d\n",f[ans.first][ans.second]);
	PUTANS(ans);
	puts("");
	return;
}
//Diaspora
//flex-block
//git config --global init.defaultBranch main
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) {
		MAIN();
	}
	return 0;
}