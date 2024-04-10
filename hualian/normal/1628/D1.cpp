#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
#define int long long
void chmx(int &tmp,int t2){(tmp<t2)?(tmp=t2):(0);}
void chmn(int &tmp,int t2){(tmp>t2)?(tmp=t2):(0);}
char In[1<<20],*Ss=In,*Tt=In;
const int N=2e3+9,p=1e9+7;
inline int read(){
	int f=0,tmp=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){tmp=tmp*10+ch-'0';ch=getchar();}
	return f?-tmp:tmp;
}
struct PI{
	double tmp;int t2;
	PI(double xx=0,int yy=0){
		tmp=xx,t2=yy;
	}
	PI operator+(const PI &k){
		return PI(tmp+k.tmp,(t2+k.t2)%p);
	}
	PI operator-(const PI &k){
		return PI(tmp-k.tmp,(t2+p-k.t2)%p);
	}
	bool operator>(const PI &k)const{
		return tmp>k.tmp;
	}
}res[N][N];
int k,m,n,T;
signed main(){
	int INV2=(p+1)/2;
	int T=read();
	while(T-->0){
		n=read(),m=read(),k=read();
		For(i,0,n)fill(res[i],res[i]+m+1,DBL_MAX/2);
		res[0][0].tmp=0;
		rep(i,n)For(j,0,m){
			int t2=0;
			if(j){
				double tmp=(res[i-1][j].tmp-res[i-1][j-1].tmp);
				tmp=tmp*0.500;
				if(tmp<0)t2=tmp=0;
				else
					if(tmp>k)t2=tmp=k;
				else
					t2=(res[i-1][j].t2-res[i-1][j-1].t2)*INV2%p;
				if(res[i-1][j-1].tmp+2*tmp<res[i-1][j].tmp)
					res[i][j]=res[i-1][j-1]+PI(tmp,t2);
				else res[i][j]=res[i-1][j]-PI(tmp,t2);
			}
			else res[i][j]=res[i-1][j];
		}
		printf("%lld\n",(res[n][m].t2%p+p)%p);
	}
	return 0;
}