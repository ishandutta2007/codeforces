#include<bits/stdc++.h>
using namespace std;
long long l,r;
int main()
{
	cin>>l>>r;
	puts("YES");
	for(;l<r;l+=2)cout<<l<<' '<<l+1<<endl;
	return 0;
}