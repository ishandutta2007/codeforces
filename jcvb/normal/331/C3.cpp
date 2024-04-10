#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;
ll f[20][10][10];
int x[20][10][10];

ll n;
int s[20];int len=0;
int main()
{
	cin>>n;
	if(n==0){
		printf("0\n");
		return 0;
	}else if(n<=9){
		printf("1\n");
		return 0;
	}
	ll tmp=n;
	while(tmp){
		s[++len]=tmp%10;
		tmp/=10;
	}
	for (int d=0;d<=9;d++)
		f[1][d][0]=1,x[1][d][0]=0;
	for (int m=1;m<=9;m++)
		for (int d=0;d<=9;d++)
			if(m>d){
				f[1][d][m]=1;
				x[1][d][m]=10+d-m;
			}else{
				f[1][d][m]=2;
				x[1][d][m]=10-m;
			}
	for (int k=2;k<=len-1;k++)
		for (int m=0;m<=9;m++)
			for (int d=0;d<=9;d++){
				ll curf=0;int curd=d;
				for (int j=9;j>=0;j--){
					curf+=f[k-1][curd][max(m,j)];
					curd=x[k-1][curd][max(m,j)];
				}
				f[k][d][m]=curf;
				x[k][d][m]=curd;
			}
	ll ans=0;int d=s[1];
	for (int k=2;k<=len+1;k++){
		int m=0;
		for (int i=k+1;i<=len;i++)m=max(m,s[i]);
		for (int j=s[k];j>=0;j--){
			ans+=f[k-1][d][max(m,j)];
			d=x[k-1][d][max(m,j)];
		}
		if(k!=len){
			s[k]=9;
			s[k+1]--;
			int j=k+1;
			while(s[j]<0){
				s[j]+=10;
				s[++j]--;
			}
		}else s[k]=0;
		while(s[len]==0)len--;
	}
	cout<<ans<<endl;
	return 0;
}