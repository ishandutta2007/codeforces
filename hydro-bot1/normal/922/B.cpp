// Hydro submission #62591fce37de167dd82bcde8@1650008014240
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n,s=0;cin>>n; 
    for(a=1;a<=n;a++)
	for(b=a;b<=n;b++)
	for(c=b;c<=n&&c<a+b;c++) 
    if(!(a^b^c)) s++;
	printf("%d\n",s);
    return 0;
}