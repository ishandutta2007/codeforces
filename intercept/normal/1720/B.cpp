#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e5+9;
int a[M];
void work(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n]+a[n-1]-a[1]-a[2]<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}