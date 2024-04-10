#include <iostream>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
	int n;
	cin>>n;
 
	int ans[n+1],x,y;
	for(int i=1;i<=n;i++) ans[i]=1;
 
	for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        ans[x]*=y;
        ans[i]*=y;
    }
 
    int cntr=0;
	for(int i=1;i<=n;i++)
	{
	    if(ans[i]==1)
	    {
	    cntr++;
	    cout<<i<<" ";
	    }
	}
 
	if(cntr==0) cout<<-1<<endl;
	return 0;
}