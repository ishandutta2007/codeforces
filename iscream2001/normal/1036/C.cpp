#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#include<bitset>
#include<vector>
#define LL long long
using namespace std;
const int N=1e5+10;
int q,tot;
LL a,b,ans;
LL p[20],f[20][2][5];
int main(){
	cin>>q;
	while(q--){
		cin>>a>>b;--a;
		ans=0;
		tot=1;
		while(1){
			p[tot]=b%10;
			b/=10;
			if(b) ++tot;
			else break;
		}
		memset(f,0,sizeof(f));
		f[tot+1][0][0]=1;
		for(int i=tot;i>=1;--i){
			for(int j=0;j<=1;++j){
				for(int k=0;k<=3;++k){
					if(!f[i+1][j][k]) continue;
					if(0<p[i]||j) f[i][1][k]+=f[i+1][j][k];
					else f[i][0][k]+=f[i+1][j][k];
					if(j)
					for(int o=1;o<=9;++o)
						f[i][1][k+1]+=f[i+1][j][k];
					else 
					for(int o=1;o<=p[i];++o){
						if(o<p[i])
						f[i][1][k+1]+=f[i+1][j][k];
						else f[i][0][k+1]+=f[i+1][j][k];
					}
				}
			}
		}
		for(int j=0;j<=1;++j)
			for(int k=0;k<=3;++k)
				ans+=f[1][j][k];
		tot=1;
		while(1){
			p[tot]=a%10;
			a/=10;
			if(a) ++tot;
			else break;
		}
		memset(f,0,sizeof(f));
		f[tot+1][0][0]=1;
		for(int i=tot;i>=1;--i){
			for(int j=0;j<=1;++j){
				for(int k=0;k<=3;++k){
					if(!f[i+1][j][k]) continue;
					if(0<p[i]||j) f[i][1][k]+=f[i+1][j][k];
					else f[i][0][k]+=f[i+1][j][k];
					if(j)
					for(int o=1;o<=9;++o)
						f[i][1][k+1]+=f[i+1][j][k];
					else 
					for(int o=1;o<=p[i];++o){
						if(o<p[i])
						f[i][1][k+1]+=f[i+1][j][k];
						else f[i][0][k+1]+=f[i+1][j][k];
					}
				}
			}
		}
		for(int j=0;j<=1;++j)
			for(int k=0;k<=3;++k)
				ans-=f[1][j][k];
		cout<<ans<<endl;
	}
}