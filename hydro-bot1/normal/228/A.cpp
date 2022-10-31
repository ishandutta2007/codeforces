// Hydro submission #6253c695ca5306014671602f@1649657494023
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,a[4],s=0;
    for(i=0;i<4;i++)
    cin>>a[i];
	sort(a,a+4);
	for(i=1;i<4;i++)
	if(a[i]==a[i-1]) s++;
    printf("%d\n",s);
    return 0;
}