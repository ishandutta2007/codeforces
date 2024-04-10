#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define c(a,b)(a<=b?jc[b]*ny[a]%mo*ny[b-(a)]%mo:0)
using namespace std;
const int N=1e5+5,mo=998244353,Q=(1<<12)+1;
int a[N],n,an;
bool bz;
void go(int x){
	if(x>n){
		if(an%360==0)bz=1;
		return;
	}
	int b=an;
	an=b+a[x];
	go(x+1);
	an=b-a[x];
	go(x+1);
	an=b;
}
int main(){
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	go(1);
	if(bz)printf("YES");else printf("NO");
}