#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
#define M 1000000007
#define N 55

ll chu(ll a,ll b){
	ll res=1,p=M-2;
	while(p){
		if(p&1){res=res*b%M;}b=b*b%M;p>>=1;
	}return a*res%M;
}

int n,x,y,i,j,k,ac,wa,n0,n1,sb[666],nn;
ll res,jb;

struct Mat
{
    ll mat[55][55]={0};
    void print(){int i,j;for(i=0;i<=n;i++){for(j=0;j<=n;j++){printf("%lld ",mat[i][j]);}puts("");}puts("");}
    //void print(){int i,j;for(i=0;i<=n;i++){for(j=0;j<=n;j++){printf("%lld ",mat[i][j]*chu(1,jb)%M);}puts("");}puts("");}
}a,ans;

Mat operator*(Mat A,Mat B){
    Mat temp;
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j <= n ;j++)
        {
            //temp.mat[i][j]=0;
            for(int k = 0 ;k <= n ;k++)
            {
                temp.mat[i][j] = (temp.mat[i][j]+A.mat[i][k]*B.mat[k][j])%M;
            }
        }
    }
    return temp;
}

Mat operator^(Mat A, int k){
    Mat base;
    for(int i=0;i<=n;i++) base.mat[i][i]=1;

    while(k)
    {
        if(k & 1) base = base * A;
        A = A * A;
        k = k >> 1; 
    }
    return base;
}


int main(){
	scanf("%d%d",&n,&k);
	jb=chu(1,n*(n-1)/2);
	for(i=1;i<=n;i++){
		scanf("%d",&sb[i]);
		if(sb[i]){n1++;}
		else{n0++;}
	}
	for(i=1;i<=n0;i++){
		if(sb[i]){wa++;}
		else{ac++;}
	}
	for(i=n0+1;i<=n;i++){
		if(sb[i]){ac++;}
		else{wa++;}
	}
	ac/=2;wa/=2;n/=2;
	
	ans.mat[0][wa]=1;
	a.mat[0][1]=n0*n1*jb%M;
	a.mat[0][0]=(1-a.mat[0][1]+M)%M;
	
	for(i=1;i<=n-1;i++){
		nn++;n0=max(0,n0-1);n1=max(0,n1-1);
		a.mat[i][i-1]=nn*nn*jb%M;
		a.mat[i][i+1]=n0*n1*jb%M;
		a.mat[i][i]=(1-a.mat[i][i+1]-a.mat[i][i-1]+M+M)%M;
	}
	nn++;n0=max(0,n0-1);n1=max(0,n1-1);
	a.mat[n][n-1]=nn*nn*jb%M;
	a.mat[n][n]=(1-a.mat[n][n-1]+M)%M;
	//a.print();
	a=a^k;
	//a.print();
	ans=ans*a;
	//ans.print();
	printf("%lld",ans.mat[0][0]);
}