// Hydro submission #6253c35248f7830132791b3f@1649656659160
#include<bits/stdc++.h>
using namespace std;
int a[12],s,t;
int main()
{
    int i,k;
    cin>>k;
    for(i=0;i<12;i++)
    cin>>a[i],t+=a[i];
    if(t<k)
    {
    	printf("-1\n");
    	return 0;
	}
	sort(a,a+12);
	for(i=11;i+1&&s<k;i--)
	s+=a[i];printf("%d\n",11-i);
    return 0;
}