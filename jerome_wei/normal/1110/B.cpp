#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e5+5;
int pos[N],s[N];

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>pos[i];
	for(int i=1;i<n;i++)s[i]=pos[i+1]-pos[i]-1;
	sort(s+1,s+n);
	int ans=pos[n]-pos[1]+1;
	for(int j=1;j<k;j++){
		int id=n-j;
//		cout<<s[id]<<endl;
		ans-=s[id];
	}
	cout<<ans<<endl;
}