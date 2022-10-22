#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
int a[Maxn+5];
int n;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ll sum_1=0,sum_2=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum_1+=a[i];
			sum_2^=a[i];
		}
		ll x=(1ll<<58);
		sum_1+=x;
		if(sum_1&1){
			x++;
			sum_1++;
		}
		sum_2^=x;
		puts("3");
		cout<<x<<' '<<(2*sum_2-sum_1)/2<<' '<<(2*sum_2-sum_1)/2<<endl;
	}	
	return 0;
}