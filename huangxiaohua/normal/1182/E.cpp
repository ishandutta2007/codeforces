#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
#define N 6
#define M 1000000007
typedef long long ll;

ll ksm(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1){res=res*a%M;}
		a=a*a%M;p>>=1;
	}return res;
}

int n,i,j;
ll k,a,b,c,d,res=1;
ll sb[5][5]={1,1,0,0,0,
			 1,0,1,0,0,
			 1,0,0,0,0,
			 1,0,0,1,0,
			 0,0,0,1,1};
struct Mat
{
    ll mat[N][N]={0};
    void print(){int i,j;for(i=1;i<=n;i++){for(j=1;j<=n;j++){printf("%d ",mat[i][j]);}puts("");}puts("");}
}mt,mt2,ans;

Mat operator*(Mat A,Mat B){
    Mat temp;
    for(int i =1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ;j++)
        {
            //temp.mat[i][j]=0;
            for(int k = 1 ;k <= n ;k++)
            {
                temp.mat[i][j] = (temp.mat[i][j]+A.mat[i][k]*B.mat[k][j])%(M-1);
            }
        }
    }
    return temp;
}

Mat operator^(Mat A, ll k){
    Mat base;
    for(int i=1;i<=n;i++) base.mat[i][i]=1;

    while(k)
    {
        if(k & 1) base = base * A;
        A = A * A;
        k = k >> 1; 
    }
    return base;
}

int main(){
	n=5;
	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++){
			mt.mat[i][j]=sb[i-1][j-1];
		}
	}
	
	scanf("%lld%lld%lld%lld%lld",&k,&a,&b,&c,&d);
	k-=3;mt2=mt^k;
	
	ans.mat[1][1]=0; ans.mat[1][2]=0; ans.mat[1][3]=1; ans.mat[1][4]=0; ans.mat[1][5]=0; 
	ans=ans*mt2;
	res=res*ksm(a,ans.mat[1][1])%M;
	
	ans.mat[1][1]=0; ans.mat[1][2]=1; ans.mat[1][3]=0; ans.mat[1][4]=0; ans.mat[1][5]=0; 
	ans=ans*mt2;
	res=res*ksm(b,ans.mat[1][1])%M;
	
	ans.mat[1][1]=1; ans.mat[1][2]=0; ans.mat[1][3]=0; ans.mat[1][4]=0; ans.mat[1][5]=0; 
	ans=ans*mt2;
	res=res*ksm(c,ans.mat[1][1])%M;
	
	ans.mat[1][1]=0; ans.mat[1][2]=0; ans.mat[1][3]=0; ans.mat[1][4]=2; ans.mat[1][5]=2; 
	ans=ans*mt2;
	res=res*ksm(d,ans.mat[1][1])%M;
	
	printf("%lld",res);
}