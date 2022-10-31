// Hydro submission #6253d30348f78301327928d9@1649660675853
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s5=0,s0=0,i,a;
    bool f=true;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a) s5++;
        else s0++;
    }
    if(s5>0&&s5<9)
    {
    	if(s0) printf("0");
    	else printf("-1");
	}
	else if(!s0) printf("-1");
	else if(!s5) printf("0");
    else
    {
    	for(i=0;i<s5/9;i++)
    	printf("555555555");
		for(i=0;i<s0;i++)
    	printf("0");
    }
    cout<<endl;
    return 0;
}