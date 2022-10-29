#include <bits/stdc++.h>
#define int         long long
#define ll          long long
#define pb          push_back
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
class Matrix{
public:
	vector<vector< int > > x;
	Matrix()
	{
		x.resize(20);
		for(int i=0;i<20;++i)x[i].resize(20,0);
		return;
	}
};
Matrix mult(Matrix a,Matrix b,int m,int n)
{
	Matrix ans;
	rep(i,0,n)
    rep(j,0,n)
    rep(k,0,n)
    ans.x[i][j]=(ans.x[i][j]+(a.x[i][k]*b.x[k][j])%hell)%hell;
	return ans;
}
Matrix expo(Matrix a,int p,int m,int n)
{
    Matrix cur;
	rep(i,0,n)cur.x[i][i]=1;
	if(p==0)return cur;
	if(p==1)return a;
	Matrix temp=expo(a,p/2,m,n);
	if(p%2==0)
    return mult(temp,temp,m,n);
	else
    {
		temp=mult(temp,temp,m,n);
		temp=mult(temp,a,m,n);
		return temp;
	}
}

signed main()
{
    io
	ll n,k,a[102],b[102],c[102],i,d[101][20][20]={0},j;
	vector < ll > ans(20),temp(20);
	for(i=0;i<20;++i)
    ans[i]=0,temp[i]=0;
	cin>>n>>k;
	for(i=0;i<n;++i)
    cin>>a[i]>>b[i]>>c[i];
    b[n-1]=k;
    Matrix alpha;
    rep(j,0,20)
    rep(k,0,20)
    if(abs(k-j)<=1) alpha.x[j][k]=1;
    else alpha.x[j][k]=0;
    for(i=0;i<n;++i)
    {
        Matrix beta=expo(alpha,b[i]-a[i],hell,c[i]+1);
        for(j=0;j<=c[i];++j)
        for(k=0;k<=c[i];++k)
        d[i][j][k]=beta.x[j][k]%hell;
    }
    for(j=0;j<=c[n-1];++j)
    ans[j]=d[n-1][j][0];
    for(i=n-2;i>=0;--i)
    {
        for(j=0;j<=c[i];++j)
        for(k=0;k<=c[i];++k)
        temp[j]=(temp[j]+(d[i][j][k]*ans[k])%hell)%hell;
        ans=temp;
        for(j=0;j<20;++j)
        temp[j]=0;
    }
    cout<<ans[0]%hell;
	return 0;
}