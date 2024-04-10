#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,it;
ll f[1050][1050][2];
string s;
ll su(ll a,ll b){
	a+=b;return (a>=M)?a-M:a;
}

bool chk(int x){
	int i;
	for(i=1;i<=m;i++){
		if(x==1)return 0;
		x=__builtin_popcount(x);
	}
	return (x==1);
}

int main(){
	//memset(f,-1,sizeof(f));
	
	cin.tie(0);
	cin>>s>>m;
	if(m==0){
		cout<<1;return 0;
	}
	it=0;
	f[0][0][1]=1;
	for(auto i:s){
		if(i=='1'){
			for(j=0;j<=1000;j++){
				f[it+1][j+1][1]=su(f[it+1][j+1][1],f[it][j][1]);
				f[it+1][j][0]=su(f[it+1][j][0],f[it][j][1]);
				f[it+1][j+1][0]=su(f[it+1][j+1][0],f[it][j][0]);
				f[it+1][j][0]=su(f[it+1][j][0],f[it][j][0]);
			}
		}
		else{
			for(j=0;j<=1000;j++){
				//f[it+1][j+1][1]=su(f[it+1][j+1][1],f[it][j][1]);
				f[it+1][j][1]=su(f[it+1][j][1],f[it][j][1]);
				f[it+1][j+1][0]=su(f[it+1][j+1][0],f[it][j][0]);
				f[it+1][j][0]=su(f[it+1][j][0],f[it][j][0]);
			}
		}
		it++;
	}
	m--;
	int res=0;
	for(i=1;i<=1000;i++){
		//printf("nmsl%d %d %d\n",i,f[it][i][0],f[it][i][1]);
		if(chk(i)){
			res=su(res,f[it][i][1]);
			res=su(res,f[it][i][0]);
		}
	}
	if(!m){
		res=su(res,M-1);
	}
	cout<<res;
}