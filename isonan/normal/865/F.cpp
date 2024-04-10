#include <cstdio>
#include <map>
#include <set>

int R,C;
long long bi[61][61],get[61][61],match[61][61];
std::map<long long,int>map[22];
std::set<long long>set[22];
char str[61];
long long Abs(long long x){return x<0?-x:x;}
int main(){
	scanf("%d%d%s",&R,&C,str+1);
	for(int i=0;i<=(R+C)<<1;i++){
		bi[i][0]=1;
		for(int j=1;j<=i;j++)
			bi[i][j]=bi[i-1][j]+bi[i-1][j-1];
	}
	for(int i=1;i<=R+C;i++)
		for(int j=0;j<=R+C;j++)
			get[i][j]=bi[i-1][R-1]*bi[j][R];
	for(int i=0,start=(R<<1)+C;i<(1<<(C+1));i++){
		int u=(R+C)-__builtin_popcount(i);
		long long ans=0;
		bool cando=1;
		for(int j=0;j<C+1;j++){
			if(str[j+start]!='?'&&((i&(1<<j))!=0)!=(str[j+start]=='A')){
				cando=0;
			}
			if(i&(1<<j))++u,ans+=get[u][j+start-u];
			else ans-=get[j+start-u][u];
		}
		if(cando)++map[__builtin_popcount(i)][ans];
		set[__builtin_popcount(i)].insert(ans);
	}
	for(int i=1;i<=C+1;i++){
		int cnt1=0,cnt2=0;
		for(int j=1;j<=i+((R-1)<<1);j++)
			if(str[j]=='A')++cnt1;
			else if(str[j]=='B')++cnt2;
		if(cnt1>R-1+i||cnt2>R-1)match[i][0]=0;
		else match[i][0]=bi[i+((R-1)<<1)-cnt1-cnt2][R-1-cnt2];
		if(cnt1>R-1||cnt2>R-1+i)match[0][i]=0;
		else match[0][i]=bi[i+((R-1)<<1)-cnt1-cnt2][R-1-cnt1];
	}
	long long fin=1e18,Ans=0;
	for(int i=0,start=(R<<1)-1;i<(1<<(C+1));i++){
		bool same=1,cando=1;
		int cnt=1;
		for(int j=1;j<C+1;j++){
			if(((i&(1<<j))!=0)!=((i&(1<<(j-1)))!=0))same=0;
			if(same)++cnt;
			if(!same&&str[j+start]!='?'&&((i&(1<<j))!=0)!=(str[j+start]=='A')){
				cando=0;
			}
		}
		int u=R-1;
		long long ans=0;
		for(int j=0;j<C+1;j++){
			if(i&(1<<j))++u,ans+=get[u][j+start-u];
			else ans-=get[j+start-u][u];
		}
		int sum=C+1-__builtin_popcount(i);
		auto now=set[sum].lower_bound(-ans);
		if(now!=set[sum].end()){
			if(fin>Abs(*now+ans))Ans=0;
			fin=std::min(fin,Abs(*now+ans));
			if(cando&&fin==Abs(*now+ans))Ans+=1ll*map[sum][*now]*((i&1)?match[cnt][0]:match[0][cnt]);
		}
		if(now!=set[sum].begin()){
			--now;
			if(fin>Abs(*now+ans))Ans=0;
			fin=std::min(fin,Abs(*now+ans));
			if(cando&&fin==Abs(*now+ans))Ans+=1ll*map[sum][*now]*((i&1)?match[cnt][0]:match[0][cnt]);
		}
	}
	printf("%lld",Ans);
}