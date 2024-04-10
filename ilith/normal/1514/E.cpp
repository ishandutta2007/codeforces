#include<bits/stdc++.h>
#define rgi register int
typedef long long ll;
using namespace std;
const int N=110;
int t,n,p[N],ans[N][N],res,x;
inline int cmp(int x,int y){
	cout<<1<<' '<<x<<' '<<y<<endl;
	return fflush(stdout),cin>>res,res;
}
inline int qry(int i,int x){
	cout<<2<<' '<<p[i]<<' '<<x+1<<' ';
	for(rgi i=0;i<=x;++i)cout<<p[i]<<' ';
	return cout<<endl,fflush(stdout),cin>>res,res;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n,x=n-2;
		for(rgi i=0;i<n;++i){
			p[i]=i;
			for(rgi j=0;j<n;++j)ans[i][j]=1;
		}
		stable_sort(p,p+n,cmp);
		for(rgi i=n-1;~i;--i){
			if(x==i){
				for(rgi j=0;j<=i;++j){
					for(rgi k=i+1;k<n;++k)ans[p[k]][p[j]]=0;
				}
				--x; 
			} 
			while(~x&&qry(i,x))--x;
		}
		cout<<3<<endl;
		for(rgi i=0;i<n;++i){
			for(rgi j=0;j<n;++j)cout<<ans[i][j];
			cout<<endl;
		}
		fflush(stdout),cin>>n;
	}
	return 0;
}