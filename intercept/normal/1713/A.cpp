#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
void work(){
	int n;
	cin>>n;
	int a[4];
	a[0]=a[1]=a[2]=a[3]=0;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		a[0]=max(a[0],x);
		a[1]=max(a[1],-x);
		a[2]=max(a[2],y);
		a[3]=max(a[3],-y);
	}
	cout<<(a[0]+a[1]+a[2]+a[3])*2<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}