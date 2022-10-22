#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=100000;
const int Maxv=200000;
typedef long long ll;
int a[Maxn+5];
int n;
bool np[Maxv+5];
int id[Maxv+5];
int p[Maxn+5],num[Maxn+5][20],p_len;
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxv;i++){
		if(!np[i]){
			id[i]=++p_len;
			p[p_len]=i;
		}
		for(int j=i*i;j>0&&j<=Maxv;j+=i){
			np[j]=1;
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;1ll*p[j]*p[j]<=a[i];j++){
			if(a[i]%p[j]==0){
				int sz=0;
				while(a[i]%p[j]==0){
					a[i]/=p[j];
					sz++;
				}
				for(int k=1;k<=sz;k++){
					num[j][k]++;
				}
			}
		}
		if(a[i]>1){
			num[id[a[i]]][1]++;
		}
	}
	ll ans=1;
	for(int i=1;i<=p_len;i++){
		for(int j=1;j<20;j++){
			if(num[i][j]>=n-1){
				ans*=p[i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}