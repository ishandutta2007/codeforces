#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1<<2;
int n;
int a[M];
void work(){
	cin>>n;
	if(n&1){
		cout<<1<<" ";
		for(int i=2;i<=n;i+=2){
			cout<<i+1<<" "<<i<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i+=2){
			cout<<i+1<<" "<<i<<" ";
		}
	}
	puts("");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}