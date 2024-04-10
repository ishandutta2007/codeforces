#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define c(a,b)(a<=b?jc[b]*ny[a]%mo*ny[b-(a)]%mo:0)
using namespace std;
const int N=5e5+5,mo=998244353,Q=(1<<12)+1;
int a[N],n,an,d[N],ds,bz,t[N],t2[N];
char c;
int main(){
	scanf("%d",&n);
	fo(i,1,n){
		scanf("\n");ds=0;
		for(;(c=getchar())=='('||c==')';){
			c=c=='(';
			if(ds&&d[ds]==1&&c==0)ds--;else d[++ds]=c;
		}
		bz=0;
		fo(i,1,ds-1)if(d[i]!=d[i+1])bz=1;
		if(!bz){
			if(d[1]){
				if(t2[ds])an++,t2[ds]--;
				else t[ds]++;
			}else{
				if(t[ds])an++,t[ds]--;
				else t2[ds]++;
			}
		}
	}
	an+=(t[0]+t2[0])>>1;
	printf("%d",an);
}