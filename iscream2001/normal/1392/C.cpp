#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
const int inf=1e9+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,d,mx;
LL K,ans;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i) {
			scanf("%d",&a[i]);
		}
		ans=0;
		for(int i=n;i>1;--i){
			if(a[i-1]>a[i]) ans+=(LL)(a[i-1]-a[i]);
		}
		cout<<ans<<endl;
	} 
	return 0;
}