#include <cstdio>
#include <vector>
#include <cstring>

char str[1010];
int A[1010],B[1010][1010];
int f[1010][1010];
std::vector<int>ord,vec[10];
int read(int *num){
	scanf("%s",str+1);
	int n=strlen(str+1);
	for(int i=1;i<=n;++i)num[i]=str[n-i+1]=='?'?-1:(str[n-i+1]-'0');
	return n;
}
int n;
int cnt[1010][11],c[10],lim[1010];
int val[1010][11];
int main(){
	int top=read(A);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)lim[i]=std::max(read(B[i]),top);
	for(int i=0;i<10;++i)scanf("%d",c+i);
	memset(f,-0x3f,sizeof f);
	f[0][n]=0;
	for(int i=1;i<=n;++i)ord.push_back(i);
	for(int i=1;i<=1001;++i){
		memset(cnt[n],0,sizeof cnt[n]);
		memset(val[n],0,sizeof val[n]);
		for(int j=n-1;~j;--j){
			memcpy(cnt[j],cnt[j+1],sizeof cnt[j]);
			memcpy(val[j],val[j+1],sizeof val[j]);
			int k=B[ord[j]][i];
			for(int l=0;l<=10;++l){
				if(l+k>=10)++cnt[j][l];
				if(((k+l)%10)||i<=lim[ord[j]])val[j][l]+=c[(k+l)%10];
			}
		}
		for(int j=0;j<=n;++j){
			for(int k=0;k<10;++k)
				if(A[i]==k||(A[i]==-1&&(k||i!=top))){
					int t=(cnt[0][k]-cnt[j][k])+cnt[j][k+1];
					int v=(val[0][k]-val[j][k])+val[j][k+1];
					f[i][n-t]=std::max(f[i][n-t],f[i-1][j]+v);
				}
		}
		for(int j=0;j<10;++j)vec[j].clear();
		for(int j=0;j<n;++j)vec[B[ord[j]][i]].push_back(ord[j]);
		ord.clear();
		for(int j=0;j<10;++j)
			for(int k=0;k<vec[j].size();++k)
				ord.push_back(vec[j][k]);
		// for(int k=0;k<=n;++k)printf("%d ",f[i][k]);putchar('\n');
	}
	printf("%d\n",f[1001][n]);
}