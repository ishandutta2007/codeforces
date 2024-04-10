#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
struct Node{
	int val;
	int id;
	friend bool operator <(Node p,Node q){
		if(p.val==q.val){
			return p.id>q.id;
		}
		return p.val<q.val;
	}
}b[Maxn+5];
int a[Maxn+5];
int n;
bool cmp(int p,int q){
	return p>q;
}
int ans[Maxn+5];
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=1;i<=n;i++){
		read(b[i].val);
		b[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		ans[b[i].id]=a[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}