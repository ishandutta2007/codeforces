#include <bits/stdc++.h>
#define DB long double
#define LL long long
using namespace std;
const int N=4e5+10;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const DB PI=acos(-1);
struct V{
    DB x,y;
    V(DB _x=0,DB _y=0){x=_x;y=_y;}
};
V operator + (V a,V b){return V(a.x+b.x,a.y+b.y);}
V operator - (V a,V b){return V(a.x-b.x,a.y-b.y);}
V operator * (V a,V b){return V(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
struct FastFourierTransform{
    int n,rev[N];
    void init(int m){
        n=1;
        while(n<m) n<<=1;
        int k=0;
        while((1<<k)<n) ++k;
        for(int i=0;i<n;++i){
            int t=0;
            for(int j=0;j<k;++j) if(i&(1<<j)) t|=(1<<(k-j-1));
            rev[i]=t;
        }
    }
    void DFT(V *a,int flag){
        for(int i=0;i<n;++i) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int l=2;l<=n;l<<=1){
            int m=l>>1;
            V wn(cos(2*PI/l),flag*sin(2*PI/l));
            for(V *p=a;p!=a+n;p+=l){
                V w(1,0);
                for(int k=0;k<m;++k){
                    V t=w*p[k+m];
                    p[k+m]=p[k]-t;
                    p[k]=p[k]+t;
                    w=w*wn;
                } 
            }
        }
        if(flag==-1) for(int i=0;i<n;++i) a[i].x/=n;
    }
    void Cheng(V *a,V *b,int m){
        init(m);
        DFT(a,1);DFT(b,1);
        for(int i=0;i<n;++i) a[i]=a[i]*b[i];
        DFT(a,-1);
    }
}fft;
V A[N],B[N];
V Amx[N],Bmx[N];
V Amn[N],Bmn[N],C[N],D[N];

int n,m,Q;
int a[N],b[N];
LL ans[N];
int main(){
    scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;++i) 
    	scanf("%d",&a[i]);
    for(int i=1;i<=n;++i) {
    	A[a[i]].x+=1;
    	if(i<n){
    		Amx[max(a[i],a[i+1])].x+=1;
    		Amn[min(a[i],a[i+1])].x+=1;
		}
	}
	for(int i=1;i<=m;++i) 
    	scanf("%d",&b[i]);
    for(int i=1;i<=m;++i) {
    	B[b[i]].x+=1;
    	if(i<m){
    		Bmx[max(b[i],b[i+1])].x+=1;
    		Bmn[min(b[i],b[i+1])].x+=1;
		}
	}
	int L=200000+3;fft.init(L);
//	for(int i=0;i<fft.n;++i) {
//		//cout<<int(A[i].x+0.5)<<endl;
//		//cout<<int(Bmx[i].x+0.5)<<endl;
//	}
    fft.DFT(A,1);fft.DFT(B,1);
    fft.DFT(Amx,1);fft.DFT(Amn,1);
    fft.DFT(Bmx,1);fft.DFT(Bmn,1);
    for(int i=0;i<fft.n;++i){
    	C[i]=Amn[i]*Bmn[i];
    	D[i]=Amx[i]*Bmx[i];
    	Amn[i]=Amn[i]*B[i];Amx[i]=Amx[i]*B[i];
    	Bmn[i]=Bmn[i]*A[i];Bmx[i]=Bmx[i]*A[i];
    	A[i]=A[i]*B[i];
	}
	fft.DFT(C,-1);fft.DFT(D,-1);
	fft.DFT(Amn,-1);fft.DFT(Amx,-1);
	fft.DFT(Bmn,-1);fft.DFT(Bmx,-1);
	fft.DFT(A,-1);
//	for(int i=0;i<fft.n;++i) {
//		//cout<<int(A[i].x+0.5)<<endl;
//		//cout<<int(D[i].x+0.5)<<endl;
//	}
	LL now=0;
	for(int i=fft.n-1;i>=0;--i){
		now+=(long long)(A[i].x+0.5);
		ans[i]+=now;
	}
	now=0;
	for(int i=0;i<fft.n;++i){
		now+=(long long)(A[i].x+0.5);
		ans[i+1]-=now;
	}
	now=0;
	for(int i=fft.n-1;i>=0;--i){
		now+=(long long)(C[i].x+0.5);
		ans[i]+=now;
	}
	now=0;
	for(int i=0;i<fft.n;++i){
		now+=(long long)(D[i].x+0.5);
		ans[i+1]-=now;
	}
	now=0;
	for(int i=0;i<fft.n;++i){
		now+=(long long)(Amx[i].x+0.5);
		now+=(long long)(Bmx[i].x+0.5);
		ans[i+1]+=now;
	}
	now=0;
	for(int i=fft.n-1;i>=0;--i){
		now+=(long long)(Amn[i].x+0.5);
		now+=(long long)(Bmn[i].x+0.5);
		ans[i]-=now;
	}
	int x;
	while(Q--){
		scanf("%d",&x);
		printf("%I64d\n",ans[x]);
	}
	return 0;
}