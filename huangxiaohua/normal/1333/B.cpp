#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,z,f,t,a[500500],b[500500];
ll sum,res;
map<ll,int> mp;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		z=f=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]>b[i]){
				if(!f){puts("NO");goto aaa;}
			}
			if(a[i]<b[i]){
				if(!z){puts("NO");goto aaa;}
			}
			if(a[i]>0){z=1;}
			if(a[i]<0){f=1;}
		}
		puts("YES");
		aaa:;
	}
}