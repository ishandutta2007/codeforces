#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll l,r,res,i,a=1,b=1;
ll j1=1,o1=2,inv2=500000004;
bool sb;
 
ll chk(ll l,ll r,ll sb){
	l-=a;r-=a;
	ll sb1,sb2;
	sb1=sb+2*l;
	sb2=sb+2*r;
	//printf("%lld %lld %lld %lld %lld\n",l,r,sb1,sb2,r-l+1);
	return (sb1%M+sb2%M)%M*((r-l+1)%M)%M*inv2%M;
}
 
int main(){
	scanf("%lld%lld",&l,&r);
	for(i=1;;i<<=1){
		
		b=a+i-1;sb^=1;
		//printf("%d %d\n",a,b);
		//printf("%d %d %d\n",sb,j1,o1);
		if(a>r){break;}
		if(sb){
			if(l>b){a=b+1;j1+=2*i;j1%=M;continue;}
			if(l<a&&r>b){
				res=(res+chk(a,b,j1))%M;goto aaa;
			}
			if(l>=a&&r<=b){
				res=(res+chk(l,r,j1))%M;goto aaa;
			}
			if(l>=a&&r>b){
				res=(res+chk(l,b,j1))%M;goto aaa;
			}
			if(l<a&&r>=a){
				res=(res+chk(a,r,j1))%M;goto aaa;
			}
			aaa:j1+=2*i;j1%=M;
		}
		else{
			if(l>b){a=b+1;o1+=2*i;o1%=M;continue;}
			if(l<a&&r>b){
				res=(res+chk(a,b,o1))%M;goto bbb;
			}
			if(l>=a&&r<=b){
				res=(res+chk(l,r,o1))%M;goto bbb;
			}
			if(l>=a&&r>b){
				res=(res+chk(l,b,o1))%M;goto bbb;
			}
			if(l<a&&r>=a){
				res=(res+chk(a,r,o1))%M;goto bbb;
			}
			bbb:o1+=2*i;o1%=M;
		}
		a=b+1;
		//printf("%lld\n",res);
	}
	printf("%lld",res);
}