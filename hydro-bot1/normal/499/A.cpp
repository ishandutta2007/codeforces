// Hydro submission #6255055d17cd4d0a417646be@1649739102388
#include<bits/stdc++.h>
using namespace std;
int m,s;
int main()
{
    int n,x,i,l,r;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
    	cin>>l>>r;
    	s+=(l-m-1)%x+r-l+1;
    	m=r;
	}
    printf("%d\n",s);
    return 0;
}