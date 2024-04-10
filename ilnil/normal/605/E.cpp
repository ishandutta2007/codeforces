#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define db double
using namespace std;
const int N=1005;
int n,a[N][N],d[N];
db f[N],_[N],_2[N];
bool can[N];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fo(i,1,n)fo(j,1,n)cin>>a[i][j];
	fo(i,1,n)_[i]=1-a[i][n]/(db)100,_2[i]=1;
	d[1]=n;can[n]=1;
	f[0]=1e18;
	fo(i,2,n){
		int w=0;
		fo(j,1,n)if(!can[j]){
			f[j]=_2[j]/(1-_[j]);
			if(f[j]<f[w])w=j;
		}
		d[i]=w;can[w]=1;
		fo(j,1,n)if(!can[j])
			_2[j]+=_[j]*a[j][w]/100*f[w],_[j]*=1-a[j][w]/(db)100;
	}
	printf("%.10lf",f[1]);
}