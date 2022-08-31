#include <cstdio>
#include <algorithm>

long long n,a[1000001],cnt,b[1000001];
int abs(int x){return x<0?-x:x;}
long long chk(long long x)
{
	long long now=0,mrk=0,fin=0;
	for(int i=1;i<=n;i++){
		if(mrk)
			fin+=1ll*std::min(a[i]%x,x-now)*(i-mrk);
		if((now+=a[i]%x)>=x)now%=x,mrk=0;
		if(!mrk){
			if(now>=((x+1ll)>>1ll))mrk=i;
			else fin+=now;
		}
	}
	return fin;
}
int main(){
	scanf("%d",&n);
	long long fin=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		cnt+=a[i];
	}
	if(cnt==1){
		puts("-1");
		return 0;
	}
	long long ans=-1;
	for(long long i=2;i*i<=cnt;i++)
		if(cnt%i==0){
			if(!~ans)ans=chk(i);
			else ans=std::min(ans,chk(i));
			while(cnt%i==0)cnt/=i;
		}
	if(cnt>1){
		if(!~ans)ans=chk(cnt);
		else ans=std::min(ans,chk(cnt));
	}
	if(ans==-1ll){
		puts("-1");
		return 0;
	}
	printf("%I64d\n",ans);
}