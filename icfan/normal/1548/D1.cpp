#include <cstdio>
#include <cassert>
typedef long long ll;
const int Maxn=6000;
struct Node{
	int x,y;
}a[Maxn+5];
int num[4][4];
int n;
int gcd(int x,int y){
	x=(x%4+4)%4,y=(y%4+4)%4;
	if(y==0){
		return x;
	}
	return gcd(y,x%y);
}
bool check(int x_1,int y_1,int x_2,int y_2,int x_3,int y_3){
	int S=(x_3*y_2+x_2*y_3+x_1*y_2+x_2*y_1+x_3*y_1+x_1*y_3)%4;
	if(S%2!=0){
		assert(0);
		return 0;
	}
	int v=gcd(x_3-x_1,y_3-y_1)+gcd(x_2-x_1,y_2-y_1)+gcd(x_3-x_2,y_3-y_2);
	v%=4;
	if(v%2!=0){
		assert(0);
		return 0;
	}
	if(((S/2-v/2)%2+2)%2!=0){
		return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		for(int x_1=0;x_1<4;x_1++){
			for(int y_1=0;y_1<4;y_1++){
				if(num[x_1][y_1]==0){
					continue;
				}
				if(check(x_1,y_1,x_1,y_1,a[i].x%4,a[i].y%4)){
					ans+=(1ll*num[x_1][y_1]*num[x_1][y_1]-num[x_1][y_1])/2;
				}
				for(int x_2=x_1;x_2<4;x_2++){
					for(int y_2=(x_2==x_1?y_1+1:0);y_2<4;y_2++){
						if(num[x_2][y_2]==0){
							continue;
						}
						if(check(x_1,y_1,x_2,y_2,a[i].x%4,a[i].y%4)){
							ans+=1ll*num[x_1][y_1]*num[x_2][y_2];
						}
					}
				}
			}
		}
		num[a[i].x%4][a[i].y%4]++;
	}
	printf("%lld\n",ans);
	return 0;
}