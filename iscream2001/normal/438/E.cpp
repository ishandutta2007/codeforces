#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;

const int P=998244353;

int qpow(int x,int y){
	x%=P;
    int re=1;
    while(y){
        if(y&1) re=1LL*re*x%P;
        x=1LL*x*x%P;y>>=1;	
    } 
    return re;
}
const int N=(1<<18)+10;
LL inv[N];
int tim=0;
const int g=3;
int rev[N];
struct NTT{
    int n;
    //LL w[N];
    int X[N],Y[N],Z1[N],Z2[N],Z3[N];
    int w[N];
    void fir(int m){
    	int l=0; for (n=1;n<=m;n<<=1) l++;
        int o;
        for(l=2,o=1;l<=n;l<<=1,++o){
        	m=l>>1;
        	int wn=qpow(g,(P-1)/l);
        	w[m]=1;
        	for(int k=1;k<m;++k){
	            w[m+k]=(LL)w[m+k-1]*wn%P;
	            	//++tim;
			}
        }
	}
    void init(int m){
        int l=0; for (n=1;n<=m;n<<=1) l++;
        for (int i=0;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
    }
    
    void DFT(int *a,int flag){
        for(int i=0;i<n;++i) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int l=2;l<=n;l<<=1){
            int m=l>>1;
            for(int *p=a;p!=a+n;p+=l){
                for(int k=0;k<m;++k){
                    int t=1LL*w[k+m]*p[k+m]%P;
                    //++tim;
                    p[k+m]=(p[k]-t+P)%P;
                    p[k]=(p[k]+t)%P;
//                    p[k+m]=(p[k]-t+P>=P)?p[k]-t:p[k]-t+P;
//                    p[k]=(p[k]+t>=P)?p[k]+t-P:p[k]+t;
                }
            }
        }
        if(flag==1) return;
        int ppp=qpow(n,P-2);
        reverse(a+1,a+n);
        for(int i=0;i<n;++i) {
            	a[i]=1LL*a[i]*ppp%P;
            	//++tim;
		}
    }
    
    void INV(int *a,int *G0,int m){
    	if(m==1){
    		G0[0]=qpow(a[0],P-2);
    		return;
		}
    	INV(a,G0,(m+1)/2);
    	init(m+m+3);
    	for(int i=0;i<m;++i) {
    		X[i]=a[i];
		}
    	for(int i=m;i<n;++i) {
    		X[i]=0;
		}
    	DFT(X,1);DFT(G0,1);
    	for(int i=0;i<n;++i) {
    		G0[i]=1LL*(2LL-(LL)X[i]*G0[i]%P+P)*G0[i]%P;
		}
    	DFT(G0,0);
    	for(int i=m;i<n;++i) {
    		G0[i]=0;
		}
    	return;
	}
	
    void Ln(int *a,int *G0,int m){
    	INV(a,G0,m);
    	init(m+m+3);
    	for(int i=1;i<m;++i){
    		X[i-1]=(LL)a[i]*i%P;
		}
		X[m-1]=0;
		for(int i=m;i<n;++i){
			G0[i]=X[i]=0;
		}
		DFT(X,1);DFT(G0,1);
		for(int i=0;i<n;++i) X[i]=(LL)G0[i]*X[i]%P;
		DFT(X,0);
		G0[0]=0;
		for(int i=1;i<m;++i) G0[i]=(LL)X[i-1]*inv[i]%P;
		for(int i=m;i<n;++i) G0[i]=0;
		return;
	}
	
	void Exp(int *a,int *G0,int m){
		if(m==1){
			G0[0]=1;
			//cout<<1<<endl;
			return;
		}
		Exp(a,G0,(m+1)/2);
		init(m+m+3);
		for(int i=0;i<n;++i) Z1[i]=0;
		Ln(G0,Z1,m);
		for(int i=0;i<m;++i) {
			Z1[i]=a[i]-Z1[i];
			if(Z1[i]<0) Z1[i]+=P;
		}
		Z1[0]++;if(Z1[0]>=P) Z1[0]-=P;
		init(m+m+3);
		DFT(G0,1);DFT(Z1,1);
		for(int i=0;i<n;++i) G0[i]=(LL)G0[i]*Z1[i]%P;
		DFT(G0,0);
		for(int i=m;i<n;++i) G0[i]=0;
		return;
	}
	
	void Pow(int *a,int *G0,LL o,LL oo,LL ooo,int m){
		int b,K,ni;
		for(int i=0;i<m;++i){
			if(a[i]>0){
				K=i;b=a[i];
				break;
			}
		}
		memset(Z3,0,sizeof(Z3));
		ni=qpow(b,P-2);
		for(int i=K;i<m;++i){
			Z3[i-K]=(LL)a[i]*ni%P;
		}
		memset(Z2,0,sizeof(Z2));
		Ln(Z3,Z2,m);
		for(int i=0;i<m;++i) Z2[i]=(LL)Z2[i]*o%P;
		Exp(Z2,G0,m);
		b=qpow(b,oo);
		for(int i=0;i<m;++i) G0[i]=(LL)G0[i]*b%P;
		if(K==0) return;
		if(ooo==1){
			for(int i=0;i<m;++i) G0[i]=0;
			return;
		}
		o=o*K;
		for(int i=m-1;i>=0&&i>=o;--i) G0[i]=G0[i-o];
		for(int i=0;i<m&&i<o;++i) G0[i]=0;
		return;
	}
	
	void sqr(int *a,int *G0,int m,int o){
		memset(Z3,0,sizeof(Z3));
		for(int i=0;i<m;++i){
			Z3[i]=a[i];
		}
		memset(Z2,0,sizeof(Z2));
		Ln(Z3,Z2,m);
		int ni=qpow(o,P-2);
		for(int i=0;i<m;++i) Z2[i]=(LL)Z2[i]*ni%P;
		Exp(Z2,G0,m);
		return;
	}
}ntt;

int n,m,ned;
LL K1,K2,K3;
char s[N];
int A[N],B[N];
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	//cout<<N<<endl;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    inv[0]=inv[1]=1;
    for(LL i=2;i<N;++i){
    	inv[i]=(P-P/i)*inv[P%i]%P;
	}
	cin>>m>>ned;n=100005;
	memset(A,0,sizeof(A));
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		A[x]-=4;
	}
	A[0]+=1;
//    for(int i=0;i<n;++i) {
//    	A[i]=i+1;
//	}
	ntt.fir(1<<17);
	ntt.sqr(A,B,n,2);
//    ntt.Pow(A,B,K1,K2,K3,n);
//    for(int i=0;i<n;++i) cout<<B[i]<<" ";cout<<endl;
    B[0]+=1;
    memcpy(A,B,sizeof(A));
    memset(B,0,sizeof(B));
    ntt.INV(A,B,n);
    for(int i=0;i<n;++i){
    	B[i]=B[i]+B[i];
    	if(B[i]>=P) B[i]-=P;
	}
	for(int i=1;i<=ned;++i) cout<<B[i]<<"\n";
    //cout<<tim<<endl;
	return 0;
} 
//int main(){
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	//cout<<N<<endl;
//    //freopen("1.in","r",stdin);
//    //freopen("1.out","w",stdout);
//    inv[0]=inv[1]=1;
//    for(LL i=2;i<N;++i){
//    	inv[i]=(P-P/i)*inv[P%i]%P;
//	}
//	cin>>n>>s;
//    int len=strlen(s);
//    K1=0;K2=0;K3=0;
//    for(int i=0;i<len;++i){
//    	K1=K1*10+s[i]-'0';
//    	if(K1>=P) {
//    		K3=1;
//    		K1=K1%P;
//		}
//    	K2=(K2*10+s[i]-'0')%(P-1);
//	}
//    for(int i=0;i<n;++i) cin>>A[i];
////    for(int i=0;i<n;++i) {
////    	A[i]=i+1;
////	}
//	ntt.fir(1<<17);
//    ntt.Pow(A,B,K1,K2,K3,n);
//    for(int i=0;i<n;++i) cout<<B[i]<<" ";cout<<endl;
//    //cout<<tim<<endl;
//	return 0;
//} 
/*


*/
//int main(){
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin>>n;
//    for(int i=0;i<n;++i) cin>>A[i];
////    for(int i=0;i<n;++i) {
////    	A[i]=i+1;
////	}
////	cout<<"?"<<endl;
//	ntt.fir(1<<17);
//    ntt.INV(A,B,n);
////    cout<<"?"<<endl;
//    for(int i=0;i<n;++i) cout<<B[i]<<" ";
//    cout<<endl;
//    //cout<<tim<<endl;
//	return 0;
//}