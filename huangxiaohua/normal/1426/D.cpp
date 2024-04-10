#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,t,n,res;
ll tmp,a,k;
map<ll,bool> sb;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a);
		tmp+=a;
		if(!tmp||sb[tmp]){res++;sb.clear();tmp=a;}
		sb[tmp]=1;
	}
	printf("%d\n",res);
}