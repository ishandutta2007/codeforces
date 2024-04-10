#include<bits/stdc++.h>
using namespace std;
typedef long long l;

int main()
{
	l arr[14];
	for(int i=0; i<14; i++) cin>>arr[i];
	l max=0;
	for(int i=0; i<14; i++)
	{
		int y=0;
		int z = arr[i]%14;
		l mn = 0;
		l xx = arr[i]/14;
		if(xx%2==0) mn+=xx;
		for(int j=(i+1)%14; j!=i; j = (j+1)%14)
		{
			y++;
			l x = arr[j]+arr[i]/14;
			if(y<=z) x++;
			if(x%2==0) mn+=x; 
		}
		if(max<mn) max = mn;
	}
	cout<<max<<"\n";
	return 0;
}