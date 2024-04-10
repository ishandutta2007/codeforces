// Hydro submission #6253d255ca530601467170f8@1649660501894
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	if(x>0)
	{
	    if(y>0) printf("0 %d %d 0\n",x+y,x+y);
	    else printf("0 %d %d 0\n",y-x,x-y);
	}
	else
	{
	    if(y>0) printf("%d 0 0 %d\n",x-y,y-x);
	    else printf("%d 0 0 %d\n",x+y,x+y);
	}
	return 0;
}