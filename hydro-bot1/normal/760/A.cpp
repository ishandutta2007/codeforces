// Hydro submission #62550f7617cd4d0a41764ec2@1649741687000
#include<bits/stdc++.h>
using namespace std;
int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int m,d,w,s=1;
	cin>>m>>d;
	w=md[m-1]-(7-d+1);
	s+=w%7?w/7+1:w/7;
	printf("%d\n",s);
	return 0;
}