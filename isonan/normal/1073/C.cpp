#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,x,y,a[200010][2],b[200010][2];
char str[200010];
bool check(int l,int r){
	int dis=abs(a[l][0]-b[r][0])+abs(a[l][1]-b[r][1]),length=r-l-1;
	if(((dis&1)!=(length&1))||length<0)return 0;
	return length>=dis;
}
int main(){
	scanf("%d%s%d%d",&n,str+1,&x,&y);
	if(abs(x)+abs(y)>n){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i][0]=a[i-1][0],a[i][1]=a[i-1][1];
		if(str[i]=='U')a[i][1]++;
		else if(str[i]=='D')a[i][1]--;
		else if(str[i]=='L')a[i][0]--;
		else if(str[i]=='R')a[i][0]++;
	}
	if(a[n][0]==x&&a[n][1]==y){
		puts("0");
		return 0;
	}
	b[n+1][0]=x,b[n+1][1]=y;
	for(int i=n;i;i--){
		b[i][0]=b[i+1][0],b[i][1]=b[i+1][1];
		if(str[i]=='U')b[i][1]--;
		else if(str[i]=='D')b[i][1]++;
		else if(str[i]=='L')b[i][0]++;
		else if(str[i]=='R')b[i][0]--;
	} 
	int fin=n+1;
	for(int i=0;i<=n;i++){
		int l=i+1,r=n+1,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(i,mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(ans!=-1)fin=min(fin,ans-i-1);
	}
	if(fin==n+1)puts("-1");
	else printf("%d",fin);
}