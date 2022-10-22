#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
void work(){
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1)puts("0");
	else cout<<min(n,m)*2-2+max(n,m)<<endl;
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
0 10 10 10
10 10 10 10
*/