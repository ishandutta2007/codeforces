#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2005,mo=1e9+7;
int n,k;
int c[10]={1110111,10010,1011101,1011011,111010,1101011,1101111,1010010,1111111,1111011};
int a[N],w[10];
bool can[N][N*10];
int d[N][10];
int get(int x,int i){
	return x/w[i]%10;
}
int pd(int x,int y){
	fo(i,0,6)if(get(x,i)>get(y,i))return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	scanf("%d %d",&n,&k);
	w[0]=1;
	fo(i,1,6)w[i]=w[i-1]*10;
	fo(i,1,n){
		scanf("\n");
		fo(j,0,6)a[i]=a[i]*10+getchar()-'0';
	}
	can[n+1][0]=1;
	fd(i,1,n){
		fo(j,0,9)if(pd(a[i],c[j])){
			int cnt=0;
			fo(k,0,6)cnt+=get(c[j],k)-get(a[i],k);
			d[i][j]=cnt;
		}else d[i][j]=-1;
		fo(j,0,min(n*7,k))if(can[i+1][j]){
			fo(k,0,9)if(d[i][k]>-1)
				can[i][j+d[i][k]]=1;
		}
	}
	if(can[1][k]){
		int p=k;
		fo(i,1,n){
			fd(j,0,9)if(d[i][j]>-1&&p-d[i][j]>=0&&can[i+1][p-d[i][j]]){
				putchar(j+'0');
				p-=d[i][j];
				break;
			}
		}
	}else printf("-1");
}