#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int INF=2e9;
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
int n;
int bin[50];
int a[N];
int q[100][100],h[100][100];
int t[N];
int mxd(int x){
	if(x==0) return -1;
	for(int i=30;i>=0;--i) if(bin[i]&x) return i;
}
int main(){
	bin[0]=1;
	for(int i=1;i<=30;++i) bin[i]=bin[i-1]<<1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&a[i]);t[i]=mxd(a[i]);
	}
	for(int i=1;i<=n-2;++i){
		if(t[i]==t[i+1]&&t[i]==t[i+2]){
			puts("1");return 0;
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			q[i][j]=0;
			h[i][j]=INF;
		}
	}
	for(int l=1;l<=n;++l){
		int now=0,tt=-1;
		for(int r=l;r<=n;++r){
			now=now^a[r];++tt;
			q[r][tt]=max(q[r][tt],now);
			h[l][tt]=min(h[l][tt],now);
		}
	}
	//cout<<h[2][0]<<endl;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			if(i>0){
				q[i][j]=max(q[i][j],q[i-1][j]);
			}
			if(j>0){
				q[i][j]=max(q[i][j],q[i][j-1]);
			}
		}
	}
	for(int i=n;i>=0;--i){
		for(int j=0;j<=n;++j){
			if(i<n){
				h[i][j]=min(h[i][j],h[i+1][j]);
			}
			if(j>0){
				h[i][j]=min(h[i][j],h[i][j-1]);
			}
		}
	}
	//cout<<h[2][0]<<endl;
	int ans=INF;
	for(int i=1;i<n;++i){
		for(int j=0;j<=n;++j){
			for(int k=0;k<=n;++k){
				if(q[i][j]>h[i+1][k]){
					if(j+k==0) cout<<i<<" "<<j<<" "<<k<<" "<<q[i][j]<<" "<<h[i+1][k]<<endl;
					ans=min(ans,j+k);
				}
			}
		}
	}
	if(ans!=INF) printf("%d\n",ans);
	else puts("-1");
	return 0;
}