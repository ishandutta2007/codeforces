#include <bits/stdc++.h>
#define int __int128

__int128 n;
__int128 Lx=1,Ly=1;
std::vector<std::pair<__int128,__int128> >vec,tem;
__int128 null=0;
__int128 calc(__int128 N){
	__int128 ans=std::max(N-Lx+1,null)*(n-Ly+1);
	for(int i=0;i<vec.size();++i){
		vec[i].first=std::max(vec[i].first,Lx);
		vec[i].second=std::max(vec[i].second,Ly);
	}
	for(int i=0;i<vec.size();++i)
		ans-=std::max((std::max(N-vec[i].first+1,null)-((i+1<vec.size())?std::max(N-vec[i+1].first+1,null):null))*(n-vec[i].second+1),null);
	return ans;
}
bool vis[1001];
__int128 a,b;
__int128 read(){
	__int128 x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(__int128 x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int query(__int128 x,__int128 y){
	write(x);putchar(' ');write(y);putchar('\n');
	fflush(stdout);
	// if(x==a&&y==b)return 0;
	// for(;;){
	// 	int opt=rand()%3+1;
	// 	if(opt==1&&x<a)return 1;
	// 	if(opt==2&&y<b)return 2;
	// 	if(opt==3&&(x>a||y>b))return 3;
	// }
	// fflush(stdout);
	// scanf("%d",&ans);
	return read();
}
signed main(){
	n=read();
	// qio>>a>>b;
	for(;;){
		// qio<<"Ly:"<<Ly<<'\n';
		__int128 sum=calc(n),x=-1,y=-1;
		__int128 l=Lx,r=n,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(calc(mid)*3ll>=sum)x=mid,r=mid-1;
			else l=mid+1;
		}
		std::reverse(vec.begin(),vec.end());
		for(int i=0;i<vec.size();++i)std::swap(vec[i].first,vec[i].second);
		std::swap(Lx,Ly);
		l=Lx,r=n;
		// qio<<sum<<' '<<calc(n)<<'\n';
		while(l<=r){
			mid=(l+r)>>1;
			if(calc(mid)*3ll>=sum)y=mid,r=mid-1;
			else l=mid+1;
		}
		std::reverse(vec.begin(),vec.end());
		for(int i=0;i<vec.size();++i)std::swap(vec[i].first,vec[i].second);
		std::swap(Lx,Ly);
		int ans=query(x,y);
		// qio<<ans<<'\n';
		if(!ans)break;
		else if(ans==1)Lx=std::max(Lx,x+1);
		else if(ans==2)Ly=std::max(Ly,y+1);
		else{
			tem=vec;
			vec.clear();
			tem.push_back(std::make_pair(x,y));
			for(int i=0;i<tem.size();++i){
				bool ans=1;
				for(int j=0;j<tem.size();++j)
					if(i!=j&&tem[i].first>=tem[j].first&&tem[i].second>=tem[j].second)
						ans=0;
				if(ans)vec.push_back(tem[i]);
			}
			std::sort(vec.begin(),vec.end());
		}
		// for(int i=0;i<vec.size();++i)qio<<'('<<vec[i].first<<' '<<vec[i].second<<')';qio<<'\n';
	}
}