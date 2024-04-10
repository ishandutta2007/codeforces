#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=1e9+7;
//const LL P=998244353;
const int N=1e6+10;
const LD eps=1e-11;
const LD eps2=1e-10;
//
LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

int lowbit(int x){
	return (x&-x);
}
int popcount(int x){
	return x==0?0:1+popcount(x-lowbit(x));
}

LL getphi(LL x){
	LL re=1;
	for(LL i=2;i*i<=x;++i){
		if(x%i==0){
			x/=i;re*=(i-1);
			while(x%i==0){
				x/=i;
				re*=i;
			}
		}
	}
	if(x>1){
		re=re*(x-1);
	}
	return re;
}

//struct jz{
//	LL x[12][12];
//};
//jz operator * (jz A,jz B){
//	jz C;
//	for(int i=1;i<=9;++i){
//		for(int j=1;j<=9;++j){
//			C.x[i][j]=0;
//		}
//	}
//	for(int i=1;i<=9;++i){
//		for(int k=1;k<=9;++k){
//			if(A.x[i][k]!=0){
//				for(int j=1;j<=9;++j){
//					(C.x[i][j]+=A.x[i][k]*B.x[k][j]%M)%=M;
//				}
//			}
//		}
//	}
//	return C;
//}
////inline char gc(){return getchar();}
//bool is_pri[N+10];
//LL pri[6000000];
////int mu[N+10];
//int cntp=0;
//
//void init_pri(){
////	mu[1]=1;
//    for(int i=2;i<=N;++i){
//        if(!is_pri[i]) {
//            pri[++cntp]=i;
//  //          mu[i]=-1;
//        }
//        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
//            is_pri[pri[j]*i]=1;
//            if(i%pri[j]==0) {
//    //        	mu[pri[j]*i]=0;
//                break;
//            }
//            else{
//      //      	mu[pri[j]*i]=-mu[i];
//			}
//        }
//    }
//}

//struct P{
//	LD x,y;
//	P(LD _x=0,LD _y=0){x=_x;y=_y;}
//}used,a[550],b[550];
//
//LD dis(P x){return x.x*x.x+x.y*x.y;}
//P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
//P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
//LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
//P operator * (P x,LD y){return P(x.x*y,x.y*y);}
//LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
//P operator / (P x,LD y){return P(x.x/y,x.y/y);}
//P dwh(P x){LD w=sqrt(dis(x));return x/w;}
//
//LL fac[1000005],finv[1000005];
//LL C(LL x,LL y,LL mod=M){
//	if(x<y) return 0;
//	if(x<=1000000) return fac[x]*finv[y]%mod*finv[x-y]%mod;
//	LL re=1;
//	y=min(y,x-y);
//	for(LL i=x-y+1;i<=x;++i){
//		re=re*i%M;
//	}
//	re=re*finv[y]%M;
//	return re;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}



int n,m,cnt,Q,K,L;
int a[N<<1];
struct SuffixAutoMaton{
	int cnt,las;
	int ch[N<<1][26],parent[N<<1],len[N<<1],siz[N<<1];
	void init(){
		cnt=0;
		las=0;
		memset(ch[0],0,sizeof(ch[0]));
		parent[0]=-1;
		len[0]=0;
		return;
	} 
	void insert(int x){
		int np=++cnt,p=las;las=np;
		memset(ch[np],0,sizeof(ch[np]));
		len[np]=len[p]+1;
		while(p>=0 && ch[p][x] == 0){
			ch[p][x]=np;
			p=parent[p];
		}
		if(p==-1){
			parent[np]=0;
		}
		else{
			int q=ch[p][x];
			if(len[q]==len[p] + 1){
				parent[np]=q;
			}
			else{
				int clone=++cnt;
				memcpy(ch[clone],ch[q],sizeof(ch[clone]));
				len[clone]=len[p]+1;
				parent[clone]=parent[q];
				while(p>=0 && ch[p][x] == q){
					ch[p][x]=clone;
					p=parent[p];
				}
				parent[np]=parent[q]=clone;
			}
		}
		siz[np]=1;
	}
}sam;
char s[N];
vector<int> V[N<<1];
int siz[N<<1];
void dfs(int x){
	siz[x]=sam.siz[x];
	for(auto y:V[x]){
		dfs(y);
		siz[x]+=siz[y];
	}
	return;
}
void MAIN(){
	int u,v;
	cin>>s;
	n=strlen(s);
	sam.init();
	for(int i=0;i<n;++i){
		sam.insert(s[i]-'a');
	}
	for(int i=0;i<=sam.cnt;++i) V[i].clear();
	for(int i=1;i<=sam.cnt;++i) V[sam.parent[i]].pb(i);
	dfs(0);
	cin>>m;
	memset(a,0,sizeof(a));
	int ans=0;
	for(int t=1;t<=m;++t){
		ans=0;
		cin>>s;
		n=strlen(s);
		int now=0,l=0;
		for(int i=0;i<n;++i){
			u=s[i]-'a';
			while(now!=-1&&sam.ch[now][u]==0) {
				now=sam.parent[now];
				l=min(l,sam.len[now]);
			}
			if(now==-1) {now=0;l=0;}
			else {now=sam.ch[now][u];l++;}
			if(l>n) l=n;
			while(sam.parent[now]!=-1 && sam.len[sam.parent[now]]>=l) now=sam.parent[now];
		}
		for(int i=0;i<n;++i){
			u=s[i]-'a';
			while(now!=-1&&sam.ch[now][u]==0) {
				now=sam.parent[now];
				l=min(l,sam.len[now]);
			}
			if(now==-1) {now=0;l=0;}
			else {now=sam.ch[now][u];l++;}
			if(l>n) l=n;
			while(sam.parent[now]!=-1 && sam.len[sam.parent[now]]>=l) now=sam.parent[now];
			if(l>=n){
				if(a[now]!=t){
					a[now]=t;
					ans+=siz[now];
				}
			}
		}
		cout<<ans<<"\n";
	}
//	cout<<sam.cnt<<endl;
//	for(int i=0;i<=sam.cnt;++i) cout<<siz[i]<<" ";cout<<endl;
//	for(int i=0;i<=sam.cnt;++i) cout<<sam.parent[i]<<" ";cout<<endl;
//	for(int i=0;i<=sam.cnt;++i){
//		for(int j=0;j<26;++j) cout<<sam.ch[i][j]<<" ";cout<<endl;
//	}
	return;
}

int main(){
	srand(time(0));
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*
aabbab
1 1 2 3 2 3
*/