#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1000010,mod=998244353;
ll ksm(ll sum,int num){
	ll ans=1;
	while(num){
		if(num&1)ans=ans*sum%mod;
		sum=sum*sum%mod;
		num>>=1;
	}return ans;
}
int f(int x){
	return x>0?0:1;
}
const int ny[3]={0,1,ksm(2,mod-2)};
int i,j,k,n,m,T,is[maxn][2],is2[maxn][2],zro,zro2,W[2];ll ans,ans1;
map<int,int>M[maxn],M2[maxn];
int main(){
	cin>>n>>m>>k;
	ans=ksm(2,n);
	ans1=ksm(2,m);
	for(i=1;i<=k;i++){
		int x=read(),y=read(),t=read();
		if(t!=1)t=-1-t;
		{
			int s=M[x][y];
			
			if(s)W[(((s+1)/2)^x^y)%2]--;
			
			if(f(is[x][0])+f(is[x][1])==0)zro--;
			else ans=ans*ny[f(is[x][0])+f(is[x][1])]%mod;
			if(s)is[x][(y+(s+1)/2)%2]--;
			M[x][y]=t;
			
			if(t)W[(((t+1)/2)^x^y)%2]++;
			
			if(t)is[x][(y+(t+1)/2)%2]++;
			if(f(is[x][0])+f(is[x][1])==0)zro++;
			else ans=ans*(f(is[x][0])+f(is[x][1]));
//			cout<<"x="<<x<<" y="<<y<<" "<<f(is[x][0])<<" "<<f(is[x][1])<<endl;
		}
		{
			int s=M2[x][y];
			if(f(is2[y][0])+f(is2[y][1])==0)zro2--;
			else ans1=ans1*ny[f(is2[y][0])+f(is2[y][1])]%mod;
			if(s)is2[y][(x+(s+1)/2)%2]--;
			M2[x][y]=t;
			if(t)is2[y][(x+(t+1)/2)%2]++;
			if(f(is2[y][0])+f(is2[y][1])==0)zro2++;
			else ans1=ans1*(f(is2[y][0])+f(is2[y][1]));
//			cout<<"x="<<x<<" y="<<y<<" "<<f(is2[y][0])<<" "<<f(is2[y][1])<<endl;
		}
		
		printf("%lld\n",((zro?0:ans)+(zro2?0:ans1)-f(W[0])-f(W[1])+mod)%mod);
	}
	return 0;
}