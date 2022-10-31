#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,l[200500],r[200500],n1,n2,a[200500],res[200500];

int main(){
	cin>>n;
	a[0]=-1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[l[n1]]){l[++n1]=i;continue;}
		if(!n2||a[l[n1]]<a[r[n2]]){r[++n2]=l[n1];n1--;}
		if(a[i]>a[l[n1]]){l[++n1]=i;continue;}
		if(!n2||a[i]<a[r[n2]]){r[++n2]=i;continue;}
		cout<<"NO";return 0;
	}
	for(i=1;i<=n2;i++)res[r[i]]=1;
	cout<<"YES\n";
	for(i=1;i<=n;i++)cout<<res[i]<<' ';
}