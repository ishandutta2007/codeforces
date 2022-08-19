#include <cstdio>
#include <algorithm>
using namespace std;

struct point{
	int val,orig;
}num[100001];
bool cmp(point a,point b){
	return a.val<b.val;
}
int d[100001],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&num[i].val),num[i].orig=i;
	std::sort(num+1,num+n+1,cmp);
	if(num[n].val==1){
		puts("NO");
		return 0;
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		if(num[i].val>1){
			pos=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		d[i]=num[i].val+d[i-1];
	}
	if(d[n]-d[pos-1]-(n-pos)*2<pos-1){
		puts("NO");
		return 0;
	}
	printf("YES %d\n%d\n",n-pos+min(pos-1,2),n-1);
	for(int i=pos;i<n;i++)printf("%d %d\n",num[i].orig,num[i+1].orig),num[i].val--,num[i+1].val--;
	if(pos==2)printf("%d %d\n",num[1].orig,num[2].orig);
	if(pos<=2)return 0;
	printf("%d %d\n%d %d\n",num[1].orig,num[pos].orig,num[2].orig,num[n].orig),num[pos].val--,num[n].val--;
	int cnt=pos;
	for(int i=3;i<pos;i++){
		while(!num[cnt].val)cnt++;
		printf("%d %d\n",num[i].orig,num[cnt].orig);
		num[cnt].val--;
	}
}