#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
int a[59];
void work(){
	int n;
	cin>>n;
	int mi=2e9;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mi=min(mi,a[i]);
	}
	if(n&1)puts("Mike");
	else{

		for(int i=1;i<=n;++i){
			if(a[i]==mi){
				if(i&1)puts("Joe");
				else puts("Mike");
				break;
			}
		}
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
4
3 3 4 2

*/