#include <cstdio>
#include <cmath>

int t;
int cnt[101];
int main(){
	scanf("%d",&t);
	for(int i=1;i<=100;++i)cnt[i]=cnt[i-1]+(i%(int)(sqrt(i))==0);
	for(int fd=1;fd<=t;++fd){
		long long L,R;
		scanf("%lld%lld",&L,&R);
		if(R<=100){
			printf("%d\n",cnt[R]-cnt[L-1]);
			continue;
		}
		long long ans=0;
		if(L<=100)ans+=cnt[100]-cnt[L-1],L=101;
		long long l=1,r=1000000000,mid,Ans=0;
		l=1,r=1000000000;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*mid<=R)Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=Ans;
		l=1,r=1000000000;
		Ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*mid<L)Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans-=Ans;

		l=1,r=1000000000;
		Ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid+1)<=R)Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=Ans;
		l=1,r=1000000000;
		Ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid+1)<L)Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans-=Ans;

		
		l=1,r=1000000000;
		Ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid+2)<=R)Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans+=Ans;
		l=1,r=1000000000;
		Ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(mid*(mid+2)<L)Ans=mid,l=mid+1;
			else r=mid-1;
		}
		ans-=Ans;
		printf("%lld\n",ans);
	}
}