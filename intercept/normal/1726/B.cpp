#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
int n,m;
int a[2009];
void work(){
	cin>>n>>m;
	if(m<n){
		puts("No");
		return;
	}
	if(n%2==0&&m%2==1){
		puts("No");
		return;
	}
	puts("Yes");
	if(n%2==0){
		for(int i=1;i<=n-2;++i)cout<<1<<" ";
		int x=m-(n-2);
		cout<<x/2<<" "<<x/2<<endl;
	}
	else{
		for(int i=1;i<=n-1;++i)cout<<1<<" ";
		int x=m-(n-1);
		cout<<x<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}