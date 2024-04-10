#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);
#define ll long long
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define N 1000005
#define mod 998244353
int a[N],n,T,i,j,x,y,m,z,k[5],g1,g2; 
ll f1,f2,dp[N][64];
string s;
int main(){
	IOS;
	//cin>>T;
	T=1;
	while(T--){
		cin>>s;
		/*
		0:,
		1:1,
		2:2,
		3:3,
		4:
		5:
		6:
		7:
		8:
		9:
		*/ 
		for(i=0;i<64;++i)if((i&7)==7)dp[s.length()][i]=1;
		for(i=s.length()-1;~i;--i){
			for(int st=0;st<64;++st){
				int st1=st>>3,st2=st&7;
				if(s[i]=='1')st1=7;
				for(j=0;j<8;++j){
					if((j&st1)==j){
						k[2]=j>>2;
						k[1]=(j>>1)&1;
						k[0]=j&1;
						int nst=0;
						for(z=2;~z;--z){
							if((s[i]=='1'&&k[z]==0)||((st>>z+3)&1))++nst;
							nst<<=1;
						}
						nst<<=2;nst|=st2;
						if((k[0]^k[1])&(k[1]^k[2]))nst|=4;
						if((k[1]^k[0])&(k[0]^k[2]))nst|=2;
						if((k[0]^k[2])&(k[2]^k[1]))nst|=1;
						(dp[i][st]+=dp[i+1][nst])%=mod;
//						cout<<i<<" "<<st<<" "<<j<<" "<<nst<<" ";
//						cout<<dp[i][st]<<" ++ \n";
					}
				}
			}
		}
		cout<<dp[0][0];
	}
}