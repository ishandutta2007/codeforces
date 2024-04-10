// Hydro submission #6253d27b48f783013279282c@1649660540654
#include<bits/stdc++.h>
using namespace std;
int t[50],i=1; 
int main()
{
	cin>>t[0];
	while(scanf("+%d",&t[i])) i++;
	sort(t,t+i);
	printf("%d",t[0]);
	for(i=1;t[i];i++)
	printf("+%d",t[i]);
	cout<<endl; 
    return 0;
}