#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
} 

int n,q;
#define Maxn 105

int a[Maxn],c[Maxn];

int b[Maxn];
pii num[100010];
int Ans[100010];

int d[Maxn];

int F[1000010];

const int Mod=1000000007;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

int S=0;

int calc(int X){
	//a[i]-b[i]-X
	rep(i,0,S)F[i]=0;
	ll sum=0;int all=0;
	F[0]=1;
	rep(i,1,n){
		all+=c[i];
		rep(k,1,all)F[k]=add(F[k],F[k-1]);
		per(k,all,c[i]+1)F[k]=dec(F[k],F[k-c[i]-1]);
		sum+=b[i]+X;
		rep(k,0,min(sum-1,(ll)all))F[k]=0;
	}
	int res=0;rep(i,0,all)res=add(res,F[i]);
	return res;
}

int main(){
	rd(n);
	int hh=1;
	rep(i,1,n){
		rd(c[i]);
		hh=mul(hh,c[i]+1);
		d[i]=d[i-1]+c[i];
	}
	S=d[n];
	rep(i,2,n){
		rd(b[i]);
		b[i]+=b[i-1];
	}
	rd(q);rep(i,1,q){
		rd(num[i].FR);num[i].SE=i;
	}
	sort(num+1,num+q+1);
	rep(i,1,q){
		int X=num[i].FR;
		if(i>1&&X==num[i-1].FR)Ans[num[i].SE]=Ans[num[i-1].SE];
		else{
			int id=num[i].SE;
		ll cur=0;
		bool fl=false,tt=false;
		rep(j,1,n){
			cur+=b[j]+X;
			if(cur>0){
				fl=true;
				if(cur>d[j])tt=true;
			}
		}
		if(tt)Ans[num[i].SE]=0;
		else if(fl)Ans[num[i].SE]=calc(X);
		else Ans[num[i].SE]=hh;
	}
	}
	rep(i,1,q)printf("%d\n",Ans[i]);
	return 0;
}