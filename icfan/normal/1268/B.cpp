#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 300000
#define ll long long
int n;
int a[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll ans=0;
	int tmp=0;
	for(int i=1;i<=n+1;i++){
//		cout<<ans<<' '<<tmp<<endl;
		if(a[i]>=tmp){
			if((a[i]-tmp)%2==0){
				ans+=(a[i]-tmp)/2;
				if(tmp>0){
					ans+=tmp/2;
					tmp--;
				}
			}
			else{
				ans+=(a[i]-tmp)/2;
				ans+=tmp/2+1;
				tmp++;
			}
		}
		else{
			ans-=(tmp-a[i]+1)/2;
			if((tmp&1)!=(a[i]&1)){
				tmp=a[i];
				ans+=(tmp+1)/2;
			}
			else{
				ans+=a[i]/2;
				tmp=a[i]-1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}