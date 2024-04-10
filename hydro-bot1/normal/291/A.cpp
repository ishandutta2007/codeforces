// Hydro submission #6253cf8048f783013279269b@1649659776826
#include<bits/stdc++.h>
using namespace std;
map<int,int>a;
int main()
{
	int n,id,s=0,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>id;
		if(id) a[id]++;  
		if(a[id]==2) s++;  
		else if(a[id]>2)  
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d",s);
	return 0;
}