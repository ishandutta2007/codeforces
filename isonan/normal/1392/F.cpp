#include <cstdio>
#include <vector>
#include <set>
#define int long long

int n,fin;
long long a[1000001],b[1000001];
bool vis[1000001];
std::vector<int>vec;
long long read(){
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
signed main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)a[i]=read();
	vec.push_back(0);
	fin=a[1];
	for(int i=2;i<=n;i++){
		for(;a[i]-a[i-1]>=2;){
			int now=vec.back();
			if(!now){
				long long tem=std::max((a[i]-a[i-1]-1)/(i)-2,0ll);
				a[i]-=tem*(i-1);
				a[i-1]+=tem;
				fin+=tem;
			}
			if(i-1-now<=a[i]-a[i-1]-1){
				if(now)vec.pop_back();
				a[i]-=i-1-now;
				a[i-1]++;
				if(!now)++fin;
			}
			else{
				if(now)vec.pop_back();
				vec.push_back(now+a[i]-a[i-1]-1);
				a[i]=a[i-1]+1;
				if(!now)++fin;
				break;
			}
		}	
		if(a[i]==a[i-1])vec.push_back(i-1);
	}
	b[0]=fin;
	for(int i=0;i<vec.size();i++)vis[vec[i]]=1;
	for(int i=1;i<=n;i++)b[i]=b[i-1]+(vis[i-1]==0);
	for(int i=1;i<=n;i++)write(b[i]),putchar(' ');
}