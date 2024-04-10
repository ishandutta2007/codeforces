#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
using namespace std;
void work(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[1]==a[2]&&a[0]%2==0)puts("YES");
	else if(a[0]==a[1]&&a[2]%2==0)puts("YES");
	else if(a[0]+a[1]==a[2])puts("YES");
	else puts("NO");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}