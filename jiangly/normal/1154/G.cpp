#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,A=1e7+5;
int n;
ll ans=1e18;
int x,y;
int pos[A];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		if(pos[a]){
			if(a<ans){
				ans=a;
				x=pos[a];
				y=i;
			}
		}else{
			pos[a]=i;
		}
	}
	for(int i=1;i<=1e7;++i){
		int a=0;
		for(int j=i;j<=1e7;j+=i){
			if(pos[j]){
				if(a){
					if(1ll*a*j/i<ans){
						ans=1ll*a*j/i;
						x=pos[a];
						y=pos[j];
					}
					break;
				}else{
					a=j;
				}
			}
		}
	}
	if(x>y){
		swap(x,y);
	}
	printf("%d %d\n",x,y);
	return 0;
}