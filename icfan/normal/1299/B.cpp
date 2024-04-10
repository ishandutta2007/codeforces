#include <cstdio>
const int Maxn=100000;
typedef long long ll;
struct Node{
	int x,y;
}a[Maxn+5];
ll dis(Node a,Node b){
	return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);
}
bool equal(Node x_1,Node y_1,Node x_2,Node y_2){
	return dis(x_1,y_1)==dis(x_2,y_2)&&1ll*(x_1.x-y_1.x)*(x_2.y-y_2.y)==1ll*(x_2.x-y_2.x)*(x_1.y-y_1.y);
}
int main(){
	int n;
	scanf("%d",&n);
	if(n&1){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	int x_1,y_1,x_2,y_2;
	for(int i=1;i<=(n>>1);i++){
		x_1=i;
		y_1=i+1;
		x_2=i+(n>>1);
		y_2=x_2+1;
		if(y_2>n){
			y_2=1;
		}
		if(!equal(a[x_1],a[y_1],a[x_2],a[y_2])){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}