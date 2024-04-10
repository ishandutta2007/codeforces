#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 150000
int a[Maxn+5];
bool in[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(in[a[i]]){
				if(in[a[i]+1]){
					continue;
				}
				in[a[i]+1]=1;
				ans++;
			}
			else{
				in[a[i]]=1;
				ans++;
			}
		}
		else{
			if(in[a[i]-1]){
				if(in[a[i]]){
					if(in[a[i]+1]){
						continue;
					}
					in[a[i]+1]=1;
					ans++;
				}
				else{
					in[a[i]]=1;
					ans++;
				}
			}
			else{
				in[a[i]-1]=1;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}