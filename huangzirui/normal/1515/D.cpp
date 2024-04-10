#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,l,r,a[maxn],Sum[maxn][2];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>l>>r;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++){
			if(i<=l)Sum[a[i]][0]++;
			else Sum[a[i]][1]++;
		}int cost=0;
		for(i=1;i<=n;i++){
			while(l>r && Sum[i][0]>Sum[i][1]+1){
				--l;++r;++cost;
				Sum[i][0]--;
				Sum[i][1]++;
			}
			while(r>l && Sum[i][1]>Sum[i][0]+1){
				--r;++l;++cost;
				Sum[i][1]--;
				Sum[i][0]++;
			}
		}
		for(i=1;i<=n;i++){
			while(l>r && Sum[i][0]>Sum[i][1]){
				--l;++r;++cost;
				Sum[i][0]--;
				Sum[i][1]++;
			}
			while(r>l && Sum[i][1]>Sum[i][0]){
				--r;++l;++cost;
				Sum[i][1]--;
				Sum[i][0]++;
			}
		}
		for(i=1;i<=n;i++)
			cost+=max(Sum[i][0]-Sum[i][1],0);
		printf("%d\n",cost);
		for(i=1;i<=n;i++)Sum[i][0]=Sum[i][1]=0;
	}
	return 0;
}