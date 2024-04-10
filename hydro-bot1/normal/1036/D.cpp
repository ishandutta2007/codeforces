// Hydro submission #614043f8dc25cbe3c3a2ed2f@1631601656775
#include<bits/stdc++.h>
using namespace std;
long long a[300010],b[300010];
int main() {
	int n,m,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cin>>m;
	for(int j=1;j<=m;j++)
		scanf("%d",&b[j]);
	int i=1,j=1;
	for(;i<=n&&j<=m;)
		if(a[i]==b[j])
			ans++,i++,j++;
		else if(a[i]>b[j])
			b[j+1]+=b[j],j++;
		else
			a[i+1]+=a[i],i++;
	if(a[n+1]!=0||b[m+1]!=0||i!=n+1||j!=m+1||a[n]!=b[m])
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}