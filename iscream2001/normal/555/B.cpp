#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
const int N=3e5+10;
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
//
//
//
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

int n,m;
struct edge{
	LL l,r;
	int id;
}c[N],b[N];
bool cmp(edge x,edge y){
	return x.l<y.l;
}
int ans[N];

pair<LL,LL> a[N];
priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > Q;
void MAIN(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;++i){
		cin>>b[i].l;b[i].id=i;
	}
	sort(b+1,b+1+m,cmp);
	int cnt=0;
	for(int i=1;i<n;++i){
		++cnt;
		c[cnt].l=a[i+1].first-a[i].second;
		c[cnt].r=a[i+1].second-a[i].first;
		c[cnt].id=i;
	}
	sort(c+1,c+1+cnt,cmp);
	while(!Q.empty()) Q.pop();
	pair<LL,int> tmp;
	int j=1;
	for(int i=1;i<=m;++i){
		while(j<=cnt&&c[j].l<=b[i].l){
			Q.push(make_pair(c[j].r,c[j].id));
			++j;
		}
		if(!Q.empty()){
			tmp=Q.top();
			if(tmp.first<b[i].l){
				cout<<"No\n";
				return;
			}
			ans[tmp.second]=b[i].id;
			Q.pop();
		}
	}
	while(j<=cnt){
		Q.push(make_pair(c[j].r,c[j].id));
		++j;
	}
	if(!Q.empty()){
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n";
	for(int i=1;i<n;++i){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
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
/*

4
9 19 6 5
20 15 16 19

*/