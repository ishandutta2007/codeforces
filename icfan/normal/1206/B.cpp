#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
int a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	ll ans=0;
	int zero=0;
	int less=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			ans++;
			zero++;
		}
		else if(a[i]>0){
			ans+=a[i]-1;
		}
		else{
			ans+=-1-a[i];
			less++;
		}
	}
	if(less&1){
		if(zero==0){
			ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}