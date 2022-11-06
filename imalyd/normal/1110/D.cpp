#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
ll rdll(){
    ll a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
void chkmax(ll &a,ll b){if(a<b)a=b;}

const int N=1000005;

int n,m,a[N];
ll d[N][3][3],v[N][3][3],s;

int main(){
	m=rd(),n=rd();while(m--)++a[rd()];
	v[0][0][0]=1;
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int l=0;l<3;l++){
	    if(!v[i-1][j][k])continue;
	    if(i>n-2&&l)continue;
		if(j+k+l<=a[i]){
			chkmax(d[i][k][l],d[i-1][j][k]+(a[i]-j-k-l)/3+l);
			v[i][k][l]=1;
		}
	}
	printf("%I64d",d[n][0][0]);
	return 0;
}