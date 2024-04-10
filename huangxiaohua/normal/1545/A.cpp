#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
int ji[100500],ou[100500],a[100500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i&1){
				ji[a[i]]++;
			}
			else{
				ou[a[i]]++;
			}
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			if(i&1){ji[a[i]]--;}
			else{ou[a[i]]--;}
		}
		for(i=1;i<=n;i++){
			if(ji[a[i]]||ou[a[i]]){puts("NO");goto aaa;}
		}
		puts("YES");
		aaa:;
		for(i=1;i<=n;i++){
			ji[a[i]]=ou[a[i]]=0;
		}
	}
}