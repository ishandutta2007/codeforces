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
	int p=1;
	for(int i=1;i<=n;++i){
		cin>>cnt[i];
		if(cnt[i]>cnt[p])p=i;
	}
	cout<<p<<endl;
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