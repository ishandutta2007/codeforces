#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>


using namespace std;
long long a,b,q;
int x,y,d,D;

int main()
{

//	freopen( "input.txt","r",stdin );
	cin>>x>>y>>a>>b;
	for(int i=1; i<=1000; i++)	
		if(x%i==0&&y%i==0)
			d=i;
	D=x*y/d;
	q=b/D-(a-1)/D;
	cout<<q;

	
	return 0;
}