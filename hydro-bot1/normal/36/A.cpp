// Hydro submission #6247f4570bc575b66aa57d10@1648882776011
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int n,i,s0=-1,s1=0,s=-1;char c;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c;
        if(c=='1')
        {
        	if(s!=-1&&s0!=s)
        	{
        		printf("NO\n");
        		return 0;
			}
        	s1++,s=s0,s0=0;
		}
        else if(s1)
        s0++;
    }
    printf("YES\n");
    return 0;
}