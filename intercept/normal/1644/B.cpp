#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int a[M];
void work(){
	int n;
	cin>>n;
	for(int i=n;i>=1;--i){
		a[n-i+1]=i;
	}
	for(int i=n;i>=1;--i){
		if(i<n)swap(a[i],a[i+1]);
		for(int j=1;j<=n;++j)cout<<a[j]<<" \n"[j==n];
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
3 6 3 19
*/