#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[105];
unordered_map<int,bool> mp;

int main(){
	for(i=1;i*i*2<=1000000005;i++){
		mp[i*i*2]=1;
	}
	for(i=1;i*i*4<=1000000005;i++){
		mp[i*i*4]=1;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(mp[n]){puts("YES");}
		else{puts("NO");}
	}
}