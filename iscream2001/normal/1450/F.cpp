#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
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
int n,m;
int a[N];

int c[N];
int tp;
struct node{
	int l,r;
}q[N];
int t[N],v[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			c[i]=0;t[i]=0;v[i]=0;
		}
		bool flag=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++c[a[i]];
			if(c[a[i]]>((n+1)/2)) flag=1;
		}
		if(flag) {
			puts("-1");
			continue;
		}
		tp=0;
		int ans=0;
		for(int i=1,j;i<=n;i=j+1){
			j=i;
			while(j<n&&a[j+1]!=a[j]) ++j;
			++tp;
			q[tp].l=a[i];
			q[tp].r=a[j];
		}
		ans=tp-1;
		for(int i=1;i<=tp;++i){
			//cout<<q[i].l<<" "<<q[i].r<<endl;
			if(q[i].l==q[i].r){
				++t[q[i].l];
			}
			else {
				++v[q[i].l];
				++v[q[i].r];
			}
		}
		int mx=0;
		for(int i=1;i<=n;++i){
			//cout<<t[i]-1<<" "<<tp-t[i]-v[i]<<" "<<t[i]<<" "<<v[i]<<endl;
			mx=max(mx,t[i]-1-(tp-t[i]-v[i]));
		}
		printf("%d\n",ans+mx);
	}
	return 0;
}