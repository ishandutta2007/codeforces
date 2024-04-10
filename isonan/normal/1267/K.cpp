#include <cstdio>
#include <cstring>

int t,cnt[21],del[21];
long long k;
void add(int x){
	for(int i=2;i<=x;i++)
		while(x%i==0)++del[i],x/=i;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%lld",&k);
		memset(cnt,0,sizeof cnt);
		int tot=0;
		for(int i=2;;i++){
			++cnt[k%i];
			k/=i;
			++tot;
			if(!k)break;
		}
		long long ans1=1,ans2=1;
		int S=cnt[0];
		for(int i=0;i<=tot;i++)
			for(int j=1;j<=cnt[i];j++)
				add(j);
		for(int i=1;i<=tot;i++){
			ans1*=(S+=cnt[i])-i+1;
			for(int i=2;i<=tot;i++)
				while(del[i]&&ans1%i==0)--del[i],ans1/=i;
		}
		if(!cnt[0]){
			printf("%lld\n",ans1-1);
			continue;
		}
		--cnt[0];S=cnt[0];
		for(int i=0;i<=tot;i++)
			for(int j=1;j<=cnt[i];j++)
				add(j);
		for(int i=1;i<tot;i++){
			ans2*=(S+=cnt[i])-i+1;
			for(int i=2;i<=tot;i++)
				while(del[i]&&ans2%i==0)--del[i],ans2/=i;
		}
		printf("%lld\n",ans1-ans2-1);
	}
}