// Hydro submission #618e0f49df417b8c5f5bfa30@1636699978014
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=(1<<22)+5;
typedef pair<int,int> Int;
int n,mn[N];
Int mx[N];
Int get(Int a,Int b){
	int t[4]={a.fi,a.se,b.fi,b.se};
	sort(t,t+4,[](int a,int b){return a>b;});
	return make_pair(t[0],t[1]);
}
bool chk(int x){
	for(int i=x;i;i=(i-1)&x)if(mn[x^i]<mx[i].se)return 1;
	return mn[x]<mx[0].se;
}
int main(){
	scanf("%d",&n);
	memset(mn,10,sizeof(mn));
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		mn[x]=min(mn[x],i);
		mx[x]=get(mx[x],make_pair(i,0));
	}
	for(int j=0;j<=21;j++){
		for(int i=(1<<21)-1;i>=0;i--){
			if((i&(1<<j))==0){
				mn[i]=min(mn[i],mn[i^(1<<j)]);
				mx[i]=get(mx[i],mx[i^(1<<j)]);
			}
		}
	}
	int ans=0;
	for(int i=21;i>=0;i--)if(chk(ans|(1<<i)))ans|=(1<<i);
	printf("%d",ans);
}