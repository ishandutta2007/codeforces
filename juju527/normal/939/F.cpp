#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxk=105,inf=0x3f3f3f3f;
int l[maxk],r[maxk];
int f[2][2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
deque<int>q;
int main(){
//    freopen("CF939F.in","r",stdin);
//    freopen("CF939F.out","w",stdout);
   	int n,k;
	n=read();k=read();
	for(int i=1;i<=k;i++){
		l[i]=read();r[i]=read();
	}
	if(r[k]<n){puts("Hungry");return 0;}
	int pre=0,now=1;
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
//	for(int i=1;i<=k;i++){
//		for(int t=0;t<=2*n;t++)f[now][t]=inf;
//		for(int t=0;t<=r[i];t++){
//			if(t-r[i]+r[i-1]>=0&&t-r[i]+r[i-1]<=r[i-1])f[now][t]=f[pre][t-r[i]+r[i-1]];
//			for(int s=r[i-1]-t;s<=r[i]-t-l[i]+r[i-1];s++){
//				if(s<0||s>r[i-1])continue;
//				f[now][t]=min(f[now][t],f[pre][s]+1);
//			}
//			for(int s=t-r[i]+r[i-1]+1;s<=t+r[i-1]-l[i];s++){
//				if(s<0||s>r[i-1])continue;
//				f[now][t]=min(f[now][t],f[pre][s]+2);
//			}
//			cout<<i<<" "<<t<<" "<<f[now][t]<<endl;
//		}
//		now^=1;pre^=1;
//	}
//	cout<<f[pre][r[k]-n];
//	return 0;
	for(int i=1;i<=k;i++){
		for(int t=0;t<=2*n;t++)f[now][t]=inf;
		for(int t=r[i]-r[i-1];t<=r[i];t++)f[now][t]=f[pre][t-r[i]+r[i-1]];
		for(int t=l[i]-r[i-1];t<=r[i];t++){
			int p=t+r[i-1]-l[i];
			while(!q.empty()&&f[pre][p]<=f[pre][q.back()])q.pop_back();
			q.push_back(p);
			while(!q.empty()&&t-r[i]+r[i-1]+1>q[0])q.pop_front();
			if(!q.empty()){
				int j=q[0];
				f[now][t]=min(f[now][t],f[pre][j]+2);
			}
		}
		q.clear();
		for(int t=r[i]-l[i]+r[i-1];t>=0;t--){
			int p=r[i]-t-l[i]+r[i-1];
			while(!q.empty()&&f[pre][p]<=f[pre][q.back()])q.pop_back();
			q.push_back(p);
			while(!q.empty()&&r[i-1]-t>q[0])q.pop_front();
			if(!q.empty()){
				int j=q[0];
				f[now][t]=min(f[now][t],f[pre][j]+1);
			}
		}
		q.clear();
		pre^=1;now^=1;
	}
	int ans=f[pre][r[k]-n];
	if(ans==inf)puts("Hungry");
	else{
		puts("Full");
		printf("%d\n",ans);
	}
    return 0;
}