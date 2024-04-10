// Hydro submission #625504fdac286d0a56b85801@1649739006212
#include<bits/stdc++.h>
using namespace std;
int f[1000000],s;
int main()
{
    int n,a,i,j,m,q;cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>a;
    	for(j=1;j<=a;j++)
    	f[++s]=i;
	}
	cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>q;
        printf("%d\n",f[q]+1);
    }
    return 0;
}