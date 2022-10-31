#include<bits/stdc++.h>
using namespace std;
#define N 105
#define M 998244353
typedef long long ll;

int n;

struct Mat
{
    ll mat[N][N]={0};
    void print(){int i,j;for(i=1;i<=n;i++){for(j=1;j<=n;j++){printf("%d ",mat[i][j]);}puts("");}puts("");}
}a;

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

Mat operator^(Mat A, int k){
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

int i,j,k,m,x,y;

ll ksm(ll k,ll p){
	ll res=1;while(p){if(p&1){res=res*k%M;}k=k*k%M,p>>=1;}return res;
}

ll bsgs(ll a,ll k){
	if(k==1){
		return 0;
	}
	if(a%M==0){
		if(k==0){return 0;}
		return -1;
	}
	map<ll,int>mp;
	ll i,n=sqrt(M)+1,sb=k,sb2=ksm(a,n);
	mp[sb]=n+1;
	for(i=1;i<n;i++){
		sb=sb*a%M;
		mp[sb]=i+1;
	}
	sb=sb2;
	for(i=1;i<=n;i++){
		if(mp[sb]){return i*n-mp[sb]+1;}
		sb=sb*sb2%M;
	}
	return -1;
}

ll fx,fy,sb,tmp;

void exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
  	//printf("%d\n",a);
  	if(fx%a){puts("-1");exit(0);}
  	tmp=fx/a;
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		a.mat[i+1][i]=1;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&a.mat[n+1-i][n]);
	}
	scanf("%d%d",&k,&m);
	a=a^(k-1);
	sb=a.mat[n][1];
	fx=bsgs(3,m);
	//cout<<sb<<' '<<fx;
	exgcd(sb,M-1,x,y);
	x=(x+M-1)%(M-1);
	fy=tmp*x%(M-1);

	printf("%d",ksm(3,fy));
}