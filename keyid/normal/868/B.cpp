#include <bits/stdc++.h>
using namespace std;

bool check(int s,int t,int x1,int x2,int x3)
{
	for (int i=s;i!=t;i=(i+1)%12)
		if (i==x1||i==x2||i==x3)
			return false;
	return true;
}

int main()
{
	int h,m,s,t1,t2;
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	m=m/5;
	s=s/5;
	if (h==12)
		h=0;
	if (t1==12)
		t1=0;
	if (t2==12)
		t2=0;
	if (check(t1,t2,h,m,s)||check(t2,t1,h,m,s))
		printf("YES");
	else
		printf("NO");
	return 0;
}