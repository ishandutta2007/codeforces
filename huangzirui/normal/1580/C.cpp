#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=400010,N=710;
int i,j,k,n,m,T,sum[N][N],x[maxn],y[maxn],ans[maxn];
int LAST[maxn],is[maxn];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)x[i]=read(),y[i]=read();
	int cnt=0,Ans=0;
	for(i=1;i<=m;i++){
		int op=read(),k=read();
		if(op==1){
			++cnt;
			LAST[k]=i;
			if(x[k]+y[k]<=N-10){
				for(j=i;j<=i+x[k]-1;j++)
					sum[x[k]+y[k]][j%(x[k]+y[k])]++;
			}else{
				for(j=i;j<=m;j+=x[k]+y[k]){
					ans[j]++;
					if(j+x[k]<=m)ans[j+x[k]]--;
				}
			}
		}else{
			--cnt;
			int T=LAST[k];
			if(x[k]+y[k]<=N-10){
				for(j=T;j<=T+x[k]-1;j++)
					sum[x[k]+y[k]][j%(x[k]+y[k])]--;
			}else{
				for(j=T;j<=m;j+=x[k]+y[k]){
					ans[j]--;
					if(j+x[k]<=m)ans[j+x[k]]++;
					if(j<i && i<=j+x[k])Ans--;
				}
			}
		}
		Ans+=ans[i];
		int Sum=Ans;
		//cout<<"Sum="<<Sum<<endl;
		for(j=1;j<N;j++){
			Sum+=sum[j][i%j];
	//		if(sum[j][i%j])cout<<j<<' '<<sum[j][i%j]<<" QWQ"<<endl;
		}
		printf("%d\n",cnt-Sum);
	}
}