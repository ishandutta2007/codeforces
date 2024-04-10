#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[200500],l,r,mx;
vector<int> v;

int md(int a,int b){
	a%=b;
	if(!a){a+=b;}
	return a;
}

int main(){
	scanf("%d",&t);
	while(t--){
		v.clear();
		scanf("%d%d%d",&n,&k,&m);
		a[0]=0;a[m+1]=n+1;k--;
		for(i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
		if((n-m)%k){puts("NO");continue;}
		
		for(i=1;i<=m+1;i++){
			if(a[i]-a[i-1]-1){
				v.push_back(a[i]-a[i-1]-1);
			}
		}
		l=0;r=n-m;
		for(i=0;i<v.size()-1;i++){
			l+=v[i];r-=v[i];
			if(l>=k/2&&r>=k/2){puts("YES");goto aaa;}
		}
		puts("NO");
		aaa:;
	}
}