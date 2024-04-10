#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define cls(x) memset(x,0,sizeof x)
#define cpy(x,y) memcpy(x,y,sizeof y)
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
#define ll long long
#define ul unsigned ll
#define ui unsigned int
#define db double
#define ldb long double
#define bit(x,y)((x)>>(y)&1)
using namespace std;
const int N=1e5+5;
int n;
int a[N],s[N];
int ans;
void pr(int x){
	printf("%d\n",x);
	exit(0);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	fo(i,1,n-1){
		int x=a[i]^a[i+1];
		if(1<i&&a[i-1]>x)pr(1);
		if(i+1<n&&x>a[i+2])pr(1);
	}
	ans=1e9;
	fo(i,0,n)fo(j,i,n)fo(k,j,n)
		if(j>i&&k>j)
			if((s[j]^s[i])>(s[k]^s[j])){
				ans=min(ans,(k-j-1)+(j-i-1));
			}
	if(ans==1e9)ans=-1;
	pr(ans);
}