#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
int n;
int cnt[29];
void work(){
	cin>>n;
	if(n&1){
		cout<<1<<" "<<2<<" "<<3<<" ";
		for(int i=n-2;i>3;--i)cout<<i<<" ";
		cout<<n-1<<" "<<n<<endl;
	}
	else{
		for(int i=n-2;i>=1;--i)cout<<i<<" ";
		cout<<n-1<<" "<<n<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
4 1
3 4 0


*/