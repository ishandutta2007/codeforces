// Hydro submission #6274c9e6bda16328ffbaf6ce@1651821031306
#include<bits/stdc++.h>
using namespace std;
int n,a[100],b[101];
int main(){
	int t,n,s,i,j;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
        memset(b,0,sizeof(b));
		for(j=0;j<n;j++)
        cin>>a[j];
		sort(a,a+n);
		for(j=0;j<n;j++)
        b[a[j]]++;
        s=0;
		for(j=0;j<101;j++)
        if(b[j]<2)
        {
            s=j;
            break;
        }
		for(j=s;j<101;j++)
        if(b[j]<1)
		{
            cout<<s+j<<"\n";
            goto next;
        }
        printf("%d\n",s?s+101:202);
		next:;
	} 
	return 0;
}