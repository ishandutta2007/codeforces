#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+10;
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
int n,K;
int a[N];
char s[N];
int cnt=0;
int q[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&K);
		scanf("%s",s+1);
		int x=0,y=0,ans=0,z=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='L') {
				++y;
				z=0;
			}
			else {
				++x;
				if(z==0) ++ans;
				else ans+=2;
				z=1;
			}
		}
		K=min(K,y);
		if(x==0){
			if(K==0) ans=0;
			else ans=K+K-1;
			printf("%d\n",ans);
			continue;
		}
		cnt=0;q[cnt]=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='L') ++q[cnt];
			else {
				++cnt;
				q[cnt]=0;
			}
		}
		x=q[0];
		y=q[cnt];
		if(cnt>1) sort(q+1,q+cnt);
		q[cnt]=x;q[cnt+1]=y;
		//cout<<cnt<<endl;
		for(int i=1;i<=cnt+1&&K>0;++i){
			//cout<<"i "<<q[i]<<" ";
			if(q[i]==0) continue;
			//cout<<q[i]<<" ";
			x=min(K,q[i]);
			ans+=2*x;
			//cout<<x<<" "<<ans<<endl;
			if(i<cnt&&x==q[i]) ++ans;
			K=K-x;
		}
		printf("%d\n",ans);
	}
	return 0;
}