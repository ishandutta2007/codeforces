#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,a[510000],ans[510000],num[35],pos[35];
struct node{
	int l,r,loc;
	bool operator<(const node &x) const{ return r<x.r;}
} b[510000];
void ins(int a,int b){
    for (int i=30;i>=0;i--)
        if (a&(1<<i)){
            if (!num[i]){
                num[i]=a;
                pos[i]=b;
                return;
            }
            if (pos[i]<b){
				swap(pos[i],b);
				swap(num[i],a);
			}
            a^=num[i];
        }
}
int query(int a){
    int ans=0;
    for (int i=30;i>=0;i--)
        if (pos[i]>=a&&ans<(ans^num[i])) ans^=num[i];
    return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&b[i].l,&b[i].r);
		b[i].loc=i;
	}
	sort(b+1,b+q+1);
	int now=0;
	for (int i=1;i<=q;i++){
		while (now<b[i].r){
			now++;
			ins(a[now],now);
		}
		ans[b[i].loc]=query(b[i].l);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}