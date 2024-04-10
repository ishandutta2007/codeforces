#include <cstdio>
#include <bitset>
#include <queue>

std::bitset<2001> f[65536];
int n,k,a[16],now;
std::priority_queue<std::pair<int,int> >heap;
void findpath(int i,int j){
	if(!i)return;
	if(j*k<=2000&&f[i][j*k]){
		++now,findpath(i,j*k);
	}
	else{
		for(int l=0;l<n;l++)
			if((i&(1<<l))&&j>=a[l]&&f[i^(1<<l)][j-a[l]]){
				heap.push(std::make_pair(now,a[l]));
				findpath(i^(1<<l),j-a[l]); 
				return;
			}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	int mx=0;
	for(int i=0;i<n;i++)scanf("%d",a+i),mx+=a[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=mx;j;--j)
			if(j%k==0&&f[i][j])f[i][j/k]=1;
		for(int j=mx+1;j<=2000;j++)f[i][j]=0;
		for(int j=0;j<n;j++)
			if(!(i&(1<<j)))f[i|(1<<j)]|=f[i]<<a[j];
	}
	if(!f[(1<<n)-1][1]){
		puts("NO");
	}
	else{
		puts("YES");
		findpath((1<<n)-1,1);
		for(int i=1;i<n;i++){
			std::pair<int,int> a,b;
			a=heap.top(),heap.pop();
			b=heap.top(),heap.pop();
			printf("%d %d\n",a.second,b.second);
			a.second+=b.second;
			while(a.second%k==0)--a.first,a.second/=k;
			heap.push(a);
		}
	}
}