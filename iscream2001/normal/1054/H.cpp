#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define DB double
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
LL likegcd(LL a,LL b,LL c,LL n){
    LL re,p;
    if(c<0)
        return likegcd(-a,-b,-c,n);
    if(a<0||b<0){
        re=likegcd(a%c+c,b%c+c,c,n);
        re+=n*(n+1)/2*((a/c)-1);
        re+=(n+1)*((b/c)-1);
        return re;
    }
    
    if(a==0) {
        re=(b/c)*(n+1);
        return re;
    }
    if(a>=c||b>=c){
        p=likegcd(a%c,b%c,c,n);
        re=n*(n+1)/(LL)2*(a/c);
        re+=(b/c)*(n+1);
        re+=p;
        return re;
    }
    LL m=(a*n+b)/c;
    p=likegcd(c,c-b-1,a,m-1);
    re=-p+n*m;
    return re;
}
const DB eps=1e-6;
const DB PI=acos(-1);
const int N=5e4+10;
const LL P=490019;
const LL pa=491,pb=499;
const LL ra=2,rb=7;

struct V{
	DB x,y;
	V(DB _x=0,DB _y=0){x=_x;y=_y;}
};

V operator + (V a,V b){return V(a.x+b.x,a.y+b.y);}
V operator - (V a,V b){return V(a.x-b.x,a.y-b.y);}
V operator * (V a,V b){return V(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
V operator / (V a,DB b){return V(a.x/b,a.y/b);}
struct FFT{
	int n;
	int rev[2050];
	void init(){
		int k=10;n=1024;
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
            V wn(cos((DB)2*PI/l),(DB)flag*sin(2*PI/l));
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
        if(flag==-1) for(int i=0;i<n;++i){
        	a[i].x/=(DB)n;
        	a[i].y/=(DB)n;
		}
    }
}fft;

int n,m;
LL c;
LL sa[P+10],sb[P+10];
LL C[P+10];
vector<int> pos;
LL La[2000],Lb[2000];
int f[2][1100][1100];
V A[2][1100][1100],B[2][1100][1100];
V a[1100],b[1100];
int main(){
	fft.init();
	cin>>n>>m>>c;
	int x;
	for(LL i=0;i<n;++i){
		scanf("%d",&x);
		sa[i*i%(P-1)]+=x;
		//cout<<i*i%(P-1)<<endl;
	}
	for(LL i=0;i<m;++i){
		scanf("%d",&x);
		sb[i*i*i%(P-1)]+=x;
		//cout<<i*i*i%(P-1)<<endl;
	}
	for(int i=0;i<=P-2;++i) if(i%pa==0||i%pb==0) pos.push_back(i);
	for(int i=0;i<=P-2;++i) if(sb[i])
		for(int j=0;j<pos.size();++j) if(sa[pos[j]]){
			x=(LL)i*(LL)pos[j]%(P-1);
			C[x]=(C[x]+sb[i]*sa[pos[j]])%P;
		}
	for(int i=0;i<=P-2;++i) if(sa[i]&&i%pa&&i%pb)
		for(int j=0;j<pos.size();++j) if(sb[pos[j]]){
			x=(LL)i*(LL)pos[j]%(P-1);
			C[x]=(C[x]+sa[i]*sb[pos[j]])%P;
		}
	//for(int i=0;i<=30;++i) cout<<C[i]<<" ";cout<<endl;
	//cout<<"y"<<endl;
	LL y=1;
	for(int i=0;i<=pa-2;++i) La[y]=i,y=y*ra%pa;
	y=1;
	for(int i=0;i<=pb-2;++i) Lb[y]=i,y=y*rb%pb;
	
	for(int i=0;i<=P-1;++i) if(i%pa&&i%pb){
		int X=i%2,Y=La[i%pa],Z=Lb[i%pb];
		A[X][Y][Z].x=sa[i]%P;B[X][Y][Z].x=sb[i]%P;f[X][Y][Z]=i;
		
		//if(Y<=10&&Z<=10)cout<<X<<" "<<Y<<" "<<Z<<" "<<i<<endl;
	}
	
	for(int i=0;i<pa;++i) for(int j=0;j<pb;++j) A[0][i][j]=A[0][i][j]+A[1][i][j],B[0][i][j]=B[0][i][j]+B[1][i][j];
	//cout<<"y"<<endl;
	for(int i=0;i<=1;++i) for(int j=0;j<pa;++j){
		//cout<<i<<" "<<j<<endl;
		fft.DFT(A[i][j],1);
	}
//	for(int i=0;i<=1;++i) for(int j=0;j<fft.n;++j) for(int k=0;k<fft.n;++k){
//		if((LL)(A[i][j][k].x+0.5)>0) cout<<i<<" "<<j<<" "<<k<<" "<<(LL)(A[i][j][k].x+0.5)<<endl;
//	}
	//for(int i=0;i<=1;++i) for(int j=0;j<=10;++j)for(int k=0;k<=10;++k) cout<<A[i][j][k].x<<" ";cout<<endl;
	for(int i=0;i<=1;++i) for(int j=0;j<pa;++j) fft.DFT(B[i][j],1);
	//for(int i=0;i<=1;++i) for(int j=0;j<=10;++j)for(int k=0;k<=10;++k) cout<<B[i][j][k].x<<" ";cout<<endl;
	for(int i=0;i<=1;++i) for(int j=0;j<fft.n;++j){
		//cout<<i<<" "<<j<<endl;
		for(int k=0;k<fft.n;++k) a[k]=A[i][k][j],b[k]=B[i][k][j];
		fft.DFT(a,1);fft.DFT(b,1);
		for(int k=0;k<fft.n;++k) a[k]=a[k]*b[k];
		//if(j<=10)for(int k=0;k<=10;++k) cout<<a[k].x<<" ";
		fft.DFT(a,-1);
		//if(j<=10)for(int k=0;k<=10;++k) cout<<a[k].x<<" ";
		for(int k=0;k<fft.n;++k) A[i][k][j]=a[k];
		//if(j<=10)for(int k=0;k<=10;++k) cout<<A[i][k][j].x<<" ";
	}
	//cout<<"y"<<endl;
//	for(int i=0;i<=1;++i) for(int j=0;j<fft.n;++j) for(int k=0;k<fft.n;++k){
//		if((LL)(A[i][j][k].x+0.5)>0) cout<<i<<" "<<j<<" "<<k<<" "<<(LL)(A[i][j][k].x+0.5)<<endl;
//	}
	for(int i=0;i<=1;++i) for(int j=0;j<fft.n;++j) fft.DFT(A[i][j],-1);
//	for(int i=0;i<=1;++i) for(int j=0;j<fft.n;++j) for(int k=0;k<fft.n;++k){
//		if((LL)(A[i][j][k].x+0.5)>0) cout<<i<<" "<<j<<" "<<k<<" "<<(LL)(A[i][j][k].x+0.5)<<endl;
//	}
//	for(int k=0;k<=100;++k) cout<<(LL)(A[0][0][k].x+0.5)<<" ";cout<<endl;
	for(int i=0;i<fft.n;++i) for(int j=0;j<fft.n;++j) A[0][i][j]=A[0][i][j]-A[1][i][j];
	//for(int k=0;k<fft.n;++k) cout<<(LL)(A[1][0][k].x+0.5)<<" ";cout<<endl;
	for(int i=0;i<=1;++i) for(int j=0;j<fft.n;++j) for(int k=0;k<fft.n;++k){
		(C[f[i][j%(pa-1)][k%(pb-1)]]+=(LL)(A[i][j][k].x+0.5))%=P;
		//if((LL)(A[i][j][k].x+0.5)>0) cout<<i<<" "<<j<<" "<<k<<" "<<(LL)(A[i][j][k].x+0.5)<<endl;
	}
	y=1;
	LL ans=0;
	//for(int i=0;i<=30;++i) cout<<C[i]<<" ";cout<<endl;
	for(int i=0;i<=P-1;++i){
		ans=(ans+y*C[i])%P;
		y=y*c%P;
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/