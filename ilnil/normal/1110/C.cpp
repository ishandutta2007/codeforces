#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;i--)
#define ll long long
#define db double
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
using namespace std;
const int N=1e5+5,mo=1e9+7;
int n;
ll a,ans;
int main(){
	scanf("%d",&n);
	fo(i,1,n){
		scanf("%I64d",&a);
		ll b=a+1;
		for(;b%2==0;b/=2);
		if(b==1){
			ans=1;
			fo(i,2,sqrtl(a))
				if(a%i==0){
					ans=a/i;
					break;
				}
		}else{
			for(ans=1;ans<=a;ans<<=1);
			ans--;
		}
		printf("%I64d\n",ans);
	}
	
}