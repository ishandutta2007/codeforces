#include<bits/stdc++.h>
#define ll long long
using namespace std;
int i,j,k,n,m,ans;
int a[510][510];
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			char ch;
			do ch=getchar();
			while(ch!='X' && ch!='.');
			if(ch=='X')a[i][j]=1;
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j]&&a[i-1][j-1]&&a[i-1][j+1]&&a[i+1][j-1]&&a[i+1][j+1])ans++;
	cout<<ans<<endl;
	return 0;
}