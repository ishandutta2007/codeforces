#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=2*200010,S=2*200000;
int i,j,k,n,m,T,a[maxn],b[maxn],sum[maxn],is[maxn*2];

bool work(int x){
	for(i=1;i<=n;i++)b[i]=a[i]>=x?1:-1;
	for(i=1;i<=n;i++)sum[i]=sum[i-1]+b[i];
	for(i=0;i<=2*S;i++)is[i]=0;
	for(i=1;i<=n;i++){//sumi-sumj=1
	//	if(x==3){cout<<i<<' '<<sum[i]<<' '<<' '<<sum[i-k]+S<<' '<<S+sum[i]-1<<endl;}
		if(i>=m)is[sum[i-m] + S]=1;
		if(is[S + sum[i] - 1] || (i>=m && sum[i]>0))return true;
	}return false;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)a[i]=read();
	int L=0,R=200000;
	while(L<=R){
		int Mid=L+R>>1;
		if(work(Mid))L=Mid+1;
		else R=Mid-1;
	}
	cout<<L-1<<endl;
}