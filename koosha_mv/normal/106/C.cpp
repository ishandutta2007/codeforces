#include<iostream>
using namespace std;
int n,m,a,b,c,d,f[1101];
int main(){
	cin>>n>>m>>c>>d;
	for(int i=c;i<=n;i++)
		f[i]=f[i-c]+d;
		
	for(int q=0;q<m;q++){
		cin>>a>>b>>c>>d;
		for(int i=0;i<a/b;i++)
			for(int j=n;j>=c;j--)
				f[j]=max(f[j],f[j-c]+d);
	}
	cout<<f[n];
}