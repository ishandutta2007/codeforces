#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define c(a,b)(a<=b?jc[b]*ny[a]%mo*ny[b-(a)]%mo:0)
using namespace std;
const int N=1e5+5,mo=998244353,Q=(1<<12)+1;
char a[10][2];
bool bz;
int main(){
	scanf("%s\n",a[0]);
	fo(i,1,5){
		scanf("%s ",a[i]);
		if(a[i][0]==a[0][0]||a[i][1]==a[0][1])bz=1;
	}
	if(bz)printf("YES");else printf("NO");
}