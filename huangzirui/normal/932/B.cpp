#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=1000010;
int i,j,k,n,m,T,w[maxn],s[maxn][10];
int work(int x){
	int X=x;
	if(x<=9)return w[x]=x;
	if(w[x])return w[x];
	int s=1;
	while(x)s*=(x%10?x%10:1),x/=10;
	return w[X]=work(s);
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(i=1;i<=1000000;i++)work(i);
	for(i=1;i<=1000000;i++)
		for(j=1;j<=9;j++)s[i][j]=s[i-1][j]+(w[i]==j);
	cin>>n;
	for(i=1;i<=n;i++){
		int l,r,k;
		l=read();r=read();k=read();
		printf("%d\n",(s[r][k]-s[l-1][k]));
	}
}