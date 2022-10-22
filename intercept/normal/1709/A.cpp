#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int a[4];
void work(){
	int x;
	cin>>x;
	for(int i=1;i<=3;++i)cin>>a[i];
	if(a[x]==0||a[a[x]]==0)puts("NO");
	else puts("YES");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}