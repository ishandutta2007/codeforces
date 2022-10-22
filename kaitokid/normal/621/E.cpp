#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;

struct matrix
{
    ll a[103][102];
    matrix()
    {

        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)a[i][j]=0;
    }
    matrix operator * (matrix& u)
    {
        matrix prod=matrix();
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
            for(int k=0;k<101;k++)
        {prod.a[i][k]+=a[i][j]*u.a[j][k];prod.a[i][k]%=mod;}
        return prod;
    }
};
matrix pw(matrix x,ll k)
{
    matrix res=x;

    k--;
    while(k>0)
    {
        if(k%2)res=res*x;
        x=x*x;
        k/=2;
    }
    return res;
}
int fr[11];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,b,k,x;
cin>>n>>b>>k>>x;
for(int i=0;i<n;i++)
{
    int u;
    cin>>u;
    fr[u]++;
}
matrix mtr=matrix();
for(int i=0;i<x;i++)
    for(int j=0;j<10;j++)
    mtr.a[i][(i*10+j)%x]+=fr[j];
mtr=pw(mtr,b);
cout<<mtr.a[0][k];
return 0;
}