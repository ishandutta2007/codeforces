#include <cstdio>
#include <algorithm>
using namespace std; 

int n,cnt[500001][2],ans,zero;
char str[500001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		int l=0,r=0;
		for(int j=0;str[j];j++){
			if(str[j]=='(')l++;
			else if(l)l--;
			else r++;
		}
		if(l&&r)continue;
		if(l)cnt[l][0]++;
		else if(r)cnt[r][1]++;
		else zero++;
	}
	for(int i=1;i<=500000;i++)ans+=min(cnt[i][0],cnt[i][1]);
	printf("%d",ans+(zero>>1));
}