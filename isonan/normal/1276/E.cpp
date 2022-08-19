#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

int a[5],b[5];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
int Abs(int x){return (x<0)?-x:x;}
int getgcd(int *a){
	int ans=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			ans=gcd(ans,Abs(a[i]-a[j]));
	return ans;
}
struct info{
	info(){ope.clear(),p.clear();}
	std::vector<std::pair<int,int> >ope,p;
	void flip(int x,int y){
		ope.push_back(std::make_pair(p[x].first,p[y].first));
		p[x].first=(p[y].first<<1)-p[x].first;
	}
	std::pair<int,int>& operator[](int n){return p[n];}
};
std::vector<std::pair<int,int> >ans;
info compress(int *a){
	info ans;
	for(int i=1;i<=4;i++)ans.p.push_back(std::make_pair(a[i],i));
	for(;;){
		std::sort(ans.p.begin(),ans.p.end());
//		puts("");
//	for(int i=0;i<4;i++)printf("%d %d\n",ans[i].first,ans[i].second);
		if(ans[0].first==ans[3].first-1)break;
		int old=(ans[3].first-ans[0].first);
		int l,r;
		l=ans[1].first,r=std::max(ans[3].first,(ans[1].first<<1)-ans[0].first);
		if(((r-l)<<2)<=(ans[3].first-ans[0].first)*3){
//			putchar('*');
			ans.flip(0,1);
			continue;
		}
		r=ans[2].first,l=std::min(ans[0].first,(ans[2].first<<1)-ans[3].first);
		if(((r-l)<<2)<=(ans[3].first-ans[0].first)*3){
//			putchar('*');
			ans.flip(3,2);
			continue;
		}
		{
			int d1=ans[3].first-ans[2].first,d0=ans[1].first-ans[0].first,tot=ans[3].first-ans[0].first;
			if(d1<(tot>>2)&&d0<(tot>>2)){
				ans.flip(0,3);
				ans.flip(1,2);
				ans.flip(2,3);
			}
			else if(d1>d0){
				ans.flip(2,3);
				ans.flip(1,2);
				ans.flip(1,3);
				ans.flip(2,3);
			}
			else{
				ans.flip(1,0);
				ans.flip(2,1);
				ans.flip(2,0);
				ans.flip(1,0);
			}
		}
	}
	if(ans[0].first&1){
		ans.flip(0,3);
		ans.flip(1,3);
		ans.flip(2,3);
	}
	std::sort(ans.p.begin(),ans.p.end());
	return ans;
}
info move(std::vector<std::pair<int,int> >pos1,std::vector<std::pair<int,int> >pos2){
	info ans;
	ans.p=pos1;
	int delta=pos2[0].first-pos1[0].first,l=0;
	std::vector<std::pair<int,int> >tem; 
//	printf("-%d\n",delta);
	for(;;){
		std::sort(ans.p.begin(),ans.p.end());
//		printf("%lld %lld %lld\n",ans[3].first,ans[0].first,Abs(delta));
		if(ans[3].first-ans[0].first>Abs(delta))break;
		++l;
		ans.flip(2,0);
		ans.flip(1,3);
	}
	for(;;){
		std::sort(ans.p.begin(),ans.p.end());
		int change=(ans[3].first-ans[0].first)<<1;
//		printf("*%d\n",change);
		for(;;){
//			printf("%d %d\n",delta,change);
			if(delta>=change){
				ans.flip(0,3);
				ans.flip(1,3);
				ans.flip(2,3);
				ans.flip(3,0);
				ans.flip(2,0);
				ans.flip(1,0);
				delta-=change;
			}
			else if(delta<=-change){
				ans.flip(1,0);
				ans.flip(2,0);
				ans.flip(3,0);
				ans.flip(2,3);
				ans.flip(1,3);
				ans.flip(0,3);
				delta+=change;
			}else break;
		}
		if(l){
			--l;
			ans.flip(0,1);
			ans.flip(3,2);
		}else break;
	}
	return ans;
}
void add(std::vector<std::pair<int,int> >tem){for(int i=0;i<tem.size();i++)if(tem[i].first!=tem[i].second)ans.push_back(tem[i]);}
signed main(){
	for(int i=1;i<=4;i++)scanf("%lld",a+i);
	for(int i=1;i<=4;i++)scanf("%lld",b+i);
	int _gcd=getgcd(a);
	if(!_gcd){
		if(getgcd(b)==0&&b[1]==a[1])puts("0");
		else puts("-1");
		return 0;
	}
	int x=((a[1]%_gcd)+_gcd)%_gcd;
	if(_gcd!=getgcd(b)||(b[1]%_gcd+_gcd)%_gcd!=(a[1]%_gcd+_gcd)%_gcd){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=4;i++)(a[i]-=x)/=_gcd,(b[i]-=x)/=_gcd;
	int cnt=0;
	for(int i=1;i<=4;i++)cnt+=(a[i]&1)-(b[i]&1);
	if(cnt){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=4;i++)
		if((a[i]+b[i])&1){
			for(int j=i+1;j<=4;j++)
				if((b[j]&1)==(a[i]&1)){
					std::swap(b[i],b[j]);
					break;
				}
		}
//	for(int i=1;i<=4;i++)printf("%d ",b[i]);putchar('\n');
	auto nowa=compress(a),nowb=compress(b);
	add(nowa.ope);
	add(move(nowa.p,nowb.p).ope);
	std::reverse(nowb.ope.begin(),nowb.ope.end());
	for(int i=0;i<nowb.ope.size();i++){
		nowb.ope[i].first=(nowb.ope[i].second<<1)-nowb.ope[i].first;
	}
	add(nowb.ope);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%lld %lld\n",ans[i].first*_gcd+x,ans[i].second*_gcd+x);
}