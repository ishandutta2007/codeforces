#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define ll long long
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define N 1000005
int a[N],n,T,i,j,x,y,m,k,g1,g2; 
ll f1,f2;
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;f1=f2=g1=g2=0;
		for(i=1;i<=k;++i){
			cin>>a[i];
			if(a[i]>=n+n)f1+=a[i]/n;
			if(a[i]>=m+m)f2+=a[i]/m;
			if(a[i]>=1ll*n*3)g1=1;
			if(a[i]>=1ll*m*3)g2=1; 
		}
		if((f1>=m&&(g1||(m&1)==0))||(f2>=n&&(g2||(n&1)==0)))cout<<"Yes\n";
		else cout<<"No\n";
		
	}
}