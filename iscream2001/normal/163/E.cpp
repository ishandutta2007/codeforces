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

int B_S(int *a,int l,int r,int x){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) return mid;
		a[mid]>x?r=mid-1:l=mid+1;
	}
	return -1;
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



int n,m,Q,K;
int num[N];
int vis[N];
vector<int> V[N];
queue<int>q;
struct Aho_Corasick_Automaton{
    int c[N][26],fail[N],cnt;
    int ins(char *s){
        int len=strlen(s);int now=0;
        for(int i=0;i<len;i++){
            int v=s[i]-'a';
            if(!c[now][v])c[now][v]=++cnt;
            now=c[now][v];
        }
        return now;
    }
    void build(){
        for(int i=0;i<26;i++)if(c[0][i])fail[c[0][i]]=0,q.push(c[0][i]);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;i++)
            if(c[u][i])fail[c[u][i]]=c[fail[u]][i],q.push(c[u][i]);
            else c[u][i]=c[fail[u]][i];
        }
    }
    
}AC;
char s[N];
char op;
int tot;
int L[N],R[N];
void dfs(int x){
	L[x]=++tot;
	for(auto y:V[x]){
		dfs(y);
	}
	R[x]=++tot;
	return;
}
LL t[N<<1];
void add(int x,int w){
	while(x<=tot){
		t[x]+=w;
		x+=lowbit(x);
	}
}
LL ask(int x){
	LL re=0;
	while(x>0){
		re+=t[x];
		x-=lowbit(x);
	}
	return re;
}
LL query(char *s){
    int len=strlen(s);int now=0;
	LL ans=0;
    for(int i=0;i<len;i++){
        now=AC.c[now][s[i]-'a'];
       // cout<<"now "<<now<<" "<<ask(L[now])<<endl;
        ans+=ask(L[now]);
    }
    return ans;
}
void MAIN(){
	LL u,v;
	cin>>n>>K;
	for(int i=1;i<=K;++i){
		cin>>s;
		num[i]=AC.ins(s);
		vis[i]=1;
		//cout<<"num "<<i<<" "<<num[i]<<endl;
	}
	AC.build();
	for(int i=1;i<=AC.cnt;++i){
		//cout<<AC.fail[i]<<" ";
		V[AC.fail[i]].pb(i);
	}
	//cout<<endl;
	tot=0;
	dfs(0);
	for(int i=1;i<=K;++i){
		add(L[num[i]],1);
		add(R[num[i]],-1);
	}
	for(int i=1;i<=n;++i){
		cin>>op;
		if(op=='+'){
			cin>>u;
			if(vis[u]==0){
				vis[u]=1;
				add(L[num[u]],1);
				add(R[num[u]],-1);
			}
		}
		if(op=='-'){
			cin>>u;
			if(vis[u]==1){
				vis[u]=0;
				add(L[num[u]],-1);
				add(R[num[u]],1);
			}
		}
		if(op=='?'){
			cin>>s;
			u=query(s);
			cout<<u<<"\n";
		}
	}
	
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

*/