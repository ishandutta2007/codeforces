#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],cnt,lst;
set<int> s;

int main(){
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		s.insert(k);
	}
	sort(a+1,a+n+1);
	for(auto i:s){
		t--;
		printf("%d\n",i-lst);lst=i;
		if(!t)return 0;
	}
	while(t--){
		puts("0");
	}
}