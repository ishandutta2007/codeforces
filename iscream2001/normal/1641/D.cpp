#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
//const int inf=1e9;
//const LD PI=acos(-1.0);
//const LL M=1e9+7;
//const int N=1e5+10;
//const LD eps=1e-6;
//
//LL qpow(LL x,LL y,LL mod=M){
//	x%=mod;
//	LL re=1;
//	while(y){
//		if(y&1) re=re*x%mod;
//		y>>=1;x=x*x%mod;
//	}
//	return re;
//}
//
//struct jz{
//	LL x[10][10];
//};
//jz operator * (jz A,jz B){
//	jz C;
//	for(int i=1;i<=6;++i){
//		for(int j=1;j<=6;++j){
//			C.x[i][j]=0;
//		}
//	}
//	for(int i=1;i<=6;++i){
//		for(int k=1;k<=6;++k){
//			if(A.x[i][k]!=0){
//				for(int j=1;j<=6;++j){
//					C.x[i][j]+=A.x[i][k]*B.x[k][j];
//				}
//			}
//		}
//	}
//	return C;
//}
////inline char gc(){return getchar();}
//bool is_pri[N+10];
//LL pri[6000000];
//int mu[N+10];
//int cntp=0;
//
//void init_pri(){
//	mu[1]=1;
//    for(int i=2;i<=N;++i){
//        if(!is_pri[i]) {
//            pri[++cntp]=i;
//            mu[i]=-1;
//        }
//        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
//            is_pri[pri[j]*i]=1;
//            if(i%pri[j]==0) {
//            	mu[pri[j]*i]=0;
//                break;
//            }
//            else{
//            	mu[pri[j]*i]=-mu[i];
//			}
//        }
//    }
//}
//
//
//
//struct P{
//	LD x,y;
//	P(LD _x=0,LD _y=0){x=_x;y=_y;}
//}used;
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
//LL C(LL x,LL y){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%M*finv[x-y]%M;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}


int n,m;
LL ans;
struct node{
	int x[6];
	int w;
}a[100005];
int b[500005];
bool cmp(node x,node y){
	return x.w<y.w;
}
map<int,int> mp;
vector<int> V[500005];
bitset<100005> d[505],F,G;
void MAIN(){
	int cnt=0,cnt2;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i].x[j];
			b[++cnt]=a[i].x[j];
		}
		cin>>a[i].w;
	}
	sort(a,a+n,cmp);
	ans=INF;
	sort(b+1,b+1+cnt);
	cnt2=1;
	for(int i=2;i<=cnt;++i){
		if(b[i]!=b[i-1]){
			b[++cnt2]=b[i];
			mp[b[i]]=cnt2;
		}
	}
	cnt=cnt2;
	cnt2=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			a[i].x[j]=mp[a[i].x[j]];
			V[a[i].x[j]].push_back(i);
		}
	}
	//for(int i=1;i<)
	//for(int i=0;i<V[1].size();++i) cout<<V[1][i]<<" ";cout<<endl;
	mp.clear();
	for(int i=0;i<n;++i){
		G.set();
		for(int k=0;k<m;++k){
			if(V[a[i].x[k]].size()<=1000){
				for(auto j : V[a[i].x[k]]){
					G.set(j,0);
				}
			}
			else{
				if(mp[a[i].x[k]]==0){
					mp[a[i].x[k]]=++cnt2;
					d[cnt2].set();
					for(auto j : V[a[i].x[k]]){
						d[cnt2].set(j,0);
					}
				}
				G&=d[mp[a[i].x[k]]];
			}
		}
		int x=G._Find_first();
		if(x<n&&a[i].w+a[x].w<ans) ans=a[i].w+a[x].w;
	}
	if(ans==INF) cout<<"-1\n";
	else cout<<ans<<"\n";
	return;
}

int main(){
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