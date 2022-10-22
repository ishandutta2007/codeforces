#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=2e9;
//const LD PI=acos(-1.0);
const LL M=998244353;
const int N=2e5+10;
const LD eps=1e-7;
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
//LL C(int x,int y,LL mod=M){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%mod*finv[x-y]%mod;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}
template<class Info,class Merge=plus<Info> > struct Segment{
	const int n;
	const Merge merge;
	vector<Info> info;
	Segment(int n): n(n),merge(Merge()),info(4<<__lg(n)){}
	Segment(vector<Info> init) : Segment(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

struct Max {
    LL x;
    Max(LL x = -INF) : x(x) {};
};

Max operator + (const Max &a, const Max &b) {
    return std::max(a.x, b.x);
}

struct Pair {
    LL ans;
    LL a;
    LL b;
    Pair() : ans(-INF), a(-INF), b(-INF) {}
    Pair(LL a, LL b) : ans(a + b), a(a), b(b) {}
};

Pair operator+(const Pair &a, const Pair &b) {
    Pair c;
    c.ans = std::max({a.ans, b.ans, a.a + b.b});
    c.a = std::max(a.a, b.a);
    c.b = std::max(a.b, b.b);
    return c;
}

int n,Q;
LL pre[500050],suf[500050];
LL c[3][500050];
vector< array<int,3> > V;
void MAIN(){
	LL now;
	cin>>n>>Q;
	for(int i=0;i<3;++i){
		for(int j=0;j<n;++j){
			cin>>c[i][j];
		}
	}
	for(int i=0;i<n;++i){
		pre[i]=c[0][i];
		if(i>0){
			pre[i]+=pre[i-1];
			pre[i]-=c[1][i-1];
		}
	}
	for(int i=n-1;i>=0;--i){
		suf[i]=suf[i+1]+c[2][i];
	} 
	now=0;
	for(int i=0;i<n;++i){
		now+=c[1][i];
		suf[i]+=now;
	}
	V.clear();
	for(int i=0;i<Q;++i){
		int l,r,k;
		cin>>l>>r>>k;
		--l;
		V.push_back({l,r,k});
	}
	sort(V.begin(),V.end());
	LL ans=-INF;
	Segment<Max> seg(n);
	for (int i=0;i<n;++i) {
        seg.modify(i,pre[i]);
    }
	for(auto x : V){
	//	cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
		auto v = seg.rangeQuery(x[0], x[1]).x;
		if (x[1] < n) {
            pre[x[1]]=max(pre[x[1]],v-x[2]);
            seg.modify(x[1], pre[x[1]]);
        }
	}
	Segment<Pair> seg2(n);
	for (int i = 0; i < n; i++) {
        seg2.modify(i, Pair(pre[i], suf[i]));
    }
    
    for (auto x : V) {
        ans = max(ans, seg2.rangeQuery(x[0], x[1]).ans - x[2]);
    }
    
    cout << ans << "\n";
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