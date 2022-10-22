#include<bits/stdc++.h>
#define db double
#define ll long long
using namespace std;
const int M=2e5+9;
const db pi=acos(-1.0);
int n,x,m;
int a[M],p[M],s[M],r[M<<1];
struct P{
	db x,y;
	P(db t1=0,db t2=0):x(t1),y(t2){}
	P operator + (const P&o)const{return P(x+o.x,y+o.y);}
	P operator - (const P&o)const{return P(x-o.x,y-o.y);}
	P operator * (const P&o)const{return P(x*o.x-y*o.y,x*o.y+y*o.x);}
};
void fft(vector<P>&A,db temp,int lim){
	for(int i=0;i<lim;++i){if(i<r[i])swap(A[i],A[r[i]]);}
	for(int mid=1;mid<lim;mid<<=1){
		P wn=P(cos(pi/mid),temp*sin(pi/mid));
		for(int len=mid<<1,j=0;j<lim;j+=len){
			P w=P(1,0);
			for(int k=j;k<j+mid;++k,w=w*wn){
				P x=A[k],y=w*A[k+mid];
				A[k]=x+y;A[k+mid]=x-y;
			}
		}
	}
}
vector<ll> mul(vector<int>A,vector<int>B){
	int N=A.size(),M=B.size(),lim=1,p=0;
	while(lim<N+M)lim<<=1,p++;
	for(int i=0;i<lim;++i){
		r[i]=(r[i>>1]>>1)|((i&1)<<(p-1));
	}
	vector<P>X(lim,0),Y(lim,0);
	for(int i=0;i<N;++i)X[i].x=A[i];
	for(int i=0;i<M;++i)Y[i].x=B[i];
	fft(X,1,lim);fft(Y,1,lim);
	for(int i=0;i<lim;++i)X[i]=X[i]*Y[i];
	fft(X,-1,lim);
	vector<ll>C(lim,0);
	for(int i=0;i<N+M;++i)C[i]=(ll)(X[i].x/lim+0.5);
	return C;
}
ll ans[M];
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<x)m++;
		p[i]=1+((a[i-1]<x)?0:p[i-1]);
	}
	for(int i=n;i>=1;--i){
		s[i]=1+((a[i+1]<x)?0:s[i+1]);
	}
	vector<int>A(m),B(m);
	for(int i=1,l=0;i<=n;++i){
		if(a[i]<x)B[l]=s[i],A[m-l-1]=p[i],l++;
	}
	vector<ll>c=mul(A,B);
	ll sum=1ll*n*(n+1)/2;
	for(int i=m-1;i<m*2-1;++i)ans[i-m+2]=c[i],sum-=c[i];
	ans[0]=sum;
	for(int i=0;i<=n;++i)cout<<ans[i]<<" ";
	return 0;
}