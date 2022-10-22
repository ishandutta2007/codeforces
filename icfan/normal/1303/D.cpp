#include <cstdio>
#include <cstring>
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
typedef long long ll;
const int Maxn=100000;
ll n;
int m;
int a[Maxn+5];
int num[75];
int main(){
	int t;
	read(t);
	ll sum;
	int ans;
	while(t--){
		memset(num,0,sizeof num);
		read(n),read(m);
		sum=0;
		for(int i=1;i<=m;i++){
			read(a[i]);
			sum+=a[i];
			int tmp=0;
			while((1<<tmp)<a[i]){
				tmp++;
			}
			num[tmp]++;
		}
		if(sum<n){
			puts("-1");
			continue;
		}
		ans=0;
		for(int i=0;i<60;i++){
			if((n>>i)&1){
				if(num[i]){
					num[i]--;
				}
				else{
					for(int j=i+1;j<60;j++){
						if(num[j]>0){
							int k=j;
							ans+=j-i;
							num[j]--;
							k--;
							while(k>=i){
								num[k]++;
								k--;
							}
							break;
						}
					}
				}
			}
			num[i+1]+=(num[i]>>1);
			num[i]&=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}