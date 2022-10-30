#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=251;
struct Matrix{
    ll size;
    double val[MAXN][MAXN];
    inline ll clear()
    {
        size=0;
        memset(val,0,sizeof(val));
    }
};

Matrix mat;
ll cnt;
double res;
double prob[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline Matrix operator *(Matrix x,Matrix y)
{
    Matrix res;
    res.clear(),res.size=x.size;
    for(register int i=0;i<x.size;i++)
    {
        for(register int j=0;j<x.size;j++)
        {
            for(register int k=0;k<x.size;k++)
            {
                res.val[i][j]=max(res.val[i][j],x.val[i][k]+y.val[k][j]);
            }
            res.val[i][j]/=2;
        }
    }
    return res;
}
int main()
{
    cnt=read();
    for(register int i=0;i<=cnt;i++)
    {
        cin>>prob[i];
    }
    mat.size=(cnt<<1);
    for(register int i=0;i<=(cnt<<1);i++)
    {
        for(register int j=0;j<=(cnt<<1);j++)
        {
			if(i+j>=cnt&&(i+cnt-j&1)==0&&i-j<=cnt&&j-i<=cnt)
			{
				mat.val[i][j]=prob[(i+cnt-j)/2];
			}
			else
			{
				mat.val[i][j]=-1e18;
			}
        }
    }
    for(register int i=0;i<50;i++)
    {
    	mat=mat*mat;
	}
	for(register int i=0;i<=(cnt<<1);i++)
	{
		res=max(res,mat.val[0][i]);
	}
	printf("%.10lf",res);
}