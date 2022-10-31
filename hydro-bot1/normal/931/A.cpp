// Hydro submission #6259200137de167dd82bce8a@1650008066437
#include<bits/stdc++.h>
using namespace std;
int s(int x)
{
	return (x+1)*x/2;
}
int main()
{
    int a,b,c;
	cin>>a>>b;
	c=abs(a-b);
	printf("%d\n",c%2?s(c/2)+s(c/2+1):2*s(c/2)); 
    return 0;
}