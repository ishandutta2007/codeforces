// Hydro submission #6253c74bca53060146716225@1649657675251
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y,k,n,x;bool f=true;
    cin>>y>>k>>n;x=k-y;
	for(;x+y<=n;x+=k)if(x>=1)
	printf("%d ",x),f=false;
	if(f) printf("-1");
    cout<<endl;
    return 0;
}