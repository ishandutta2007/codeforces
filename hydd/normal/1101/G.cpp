#include<cstdio>
using namespace std;
int n,x,a[210000],num[35],ans;
bool ins(int x){
    for (int i=30;i>=0;i--)
        if (x&(1<<i)){
            if (!num[i]){ num[i]=x; return true;}
            x^=num[i];
        }
    return false;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=a[i-1]^x;
	}
	if (!a[n]){
		puts("-1");
		return 0;
	}
	for (int i=n;i>=1;i--)
		if (ins(a[i])) ans++;
	printf("%d\n",ans);
	return 0;
}