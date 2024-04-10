#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
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
const int Maxn=100000;
int a[3][Maxn+5];
int n[3];
ll x_2(int x){
	return 1ll*x*x;
}
int main(){
	int T;
	read(T);
	ll ans;
	while(T--){
		for(int i=0;i<3;i++){
			read(n[i]);
		}
		for(int i=0;i<3;i++){
			for(int j=1;j<=n[i];j++){
				read(a[i][j]);
			}
			sort(a[i]+1,a[i]+1+n[i]);
		}
		ans=x_2(a[0][1]-a[1][1])+x_2(a[0][1]-a[2][1])+x_2(a[1][1]-a[2][1]);
		for(int i=0;i<3;i++){
			if(i!=0){
				swap(a[i],a[0]);
				swap(n[i],n[0]);
			}
			for(int j=1;j<=n[0];j++){
				int pos_1,pos_2;
				pos_1=upper_bound(a[1]+1,a[1]+1+n[1],a[0][j])-a[1];
				pos_1--;
				pos_2=lower_bound(a[2]+1,a[2]+1+n[2],a[0][j])-a[2];
				if(pos_1>0&&pos_1<=n[1]&&pos_2>0&&pos_2<=n[2]){
					ans=min(ans,x_2(a[0][j]-a[1][pos_1])+x_2(a[0][j]-a[2][pos_2])+x_2(a[1][pos_1]-a[2][pos_2]));
				}
				pos_1=lower_bound(a[1]+1,a[1]+1+n[1],a[0][j])-a[1];
				pos_2=upper_bound(a[2]+1,a[2]+1+n[2],a[0][j])-a[2];
				pos_2--;
				if(pos_1>0&&pos_1<=n[1]&&pos_2>0&&pos_2<=n[2]){
					ans=min(ans,x_2(a[0][j]-a[1][pos_1])+x_2(a[0][j]-a[2][pos_2])+x_2(a[1][pos_1]-a[2][pos_2]));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}