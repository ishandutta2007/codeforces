#include<bits/stdc++.h>
using namespace std;
const long long inf=2000000000000000000ll;
template <typename T> inline void read(T& A){T x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();A=x*f;}
template <typename T> inline void write(T a){if(a>9)write(a/10);putchar(a%10+'0');}
long long T,x,y;
long long aa[10];//(+1,+1),(0,+1),(-1,0),(-1,-1),(0,-1),(+1,0) 
long long dx[10]={1,0,-1,-1,0,1};
long long dy[10]={1,1,0,-1,-1,0};
long long work(long long x,long long y,long long i,long long j){
	long long a,b,c,d,e,f;
	a=dx[i];
	b=dx[j];
	c=-x;
	d=dy[i];
	e=dy[j];
	f=-y;
	if(a*e==b*d)return inf;
	long long xx=(b*f-e*c)/(a*e-b*d),yy=(a*f-d*c)/(b*d-a*e);
	if(xx<0||yy<0){
		return inf;
	}
	return xx*aa[i]+yy*aa[j];
}
int main(){
	read(T);
	while(T--){
		read(x),read(y);
		for(long long i=0;i<6;i++){
			read(aa[i]);
		}
		long long ans=inf;
		for(long long i=0;i<6;i++){
			for(long long j=0;j<6;j++){
				ans=min(ans,work(x,y,i,j));
			}
		}
		write(ans);
		puts("");
	}
	return 0;
}