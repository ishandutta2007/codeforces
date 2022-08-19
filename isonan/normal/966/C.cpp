#include <cstdio>
#include <vector>
#include <cstring>

long long Xor[61][100001],n,top[61],ans[100001],anstop;
long long tempo[100001];
std::vector<long long>::iterator it1,it2;
int main(){
	scanf("%I64d",&n);
	for(long long i=1,tem,bit;i<=n;i++){
		scanf("%I64d",&tem);
		for(long long j=60ll;~j;--j)
			if(tem&(1ll<<j)){
				Xor[j][++top[j]]=tem;
				break;
			}
	}
	for(long long i=60ll;~i;--i){
		int tem=0,it1,it2;
		for(it1=it2=1;it1<=top[i]||it2<=anstop;)
			if((!(tempo[tem]&(1ll<<i)))&&it1<=top[i]){
				++tem;
				tempo[tem]=tempo[tem-1]^Xor[i][it1++];
			}
			else if(it2<=anstop){
				++tem;
				tempo[tem]=tempo[tem-1]^ans[it2++];
			}
			else break;
		for(int j=tem;j;j--)tempo[j]^=tempo[j-1];
		if(it1<=top[i]&&it1){
			puts("No");
			return 0;
		}
		memcpy(ans,tempo,sizeof ans);
		anstop=tem;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)printf("%I64d ",ans[i]);
}