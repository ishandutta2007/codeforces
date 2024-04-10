#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxn=400005,N=655;
int n,m,T,sum[N][N],x[maxn],y[maxn],ans[maxn],tans,lst[maxn],is[maxn],cnt,Ans;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	for(int i=1;i<=m;i++){
		int op=read(),k=read(),s=x[k]+y[k];
		if(op==1){
			lst[k]=i;
			if(s+5<=N)
				for(int j=i;j<=i+x[k]-1;j++)
					sum[s][j%s]++;
            else{
				for(int j=i;j<=m;j+=s){
					ans[j]++;
					if(j+x[k]<=m)ans[j+x[k]]--;
				}
			}
            cnt++;
		}
        else{
			int T=lst[k];
			if(s+5<=N)
				for(int j=T;j<=T+x[k]-1;j++)
					sum[s][j%s]--;
            else{
				for(int j=T;j<=m;j+=s){
					ans[j]--;
					if(j+x[k]<=m)ans[j+x[k]]++;
					if(j<i&&i<=j+x[k])Ans--;
				}
			}
            cnt--;
		}
		Ans+=ans[i];tans=cnt-Ans;
		for(int j=1;j<N;j++)tans-=sum[j][i%j];
		printf("%d\n",tans);
	}
    return 0;
}