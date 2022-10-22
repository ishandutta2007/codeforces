#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 400
int a[Maxn+5];
int main(){
	int q;
	int n;
	scanf("%d",&q);
	int f,t;
	bool can;
	int sum;
	while(q--){
		scanf("%d",&n);
		n<<=2;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		f=1,t=n;
		can=1;
		sum=-1;
		while(f<t){
			if(a[f]!=a[f+1]||a[t]!=a[t-1]){
				can=0;
				break;
			}
			if(sum==-1){
				sum=a[f]*a[t];
			}
			else{
				if(sum!=a[f]*a[t]){
					can=0;
					break;
				}
			}
			f+=2,t-=2;
		}
		if(can){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}