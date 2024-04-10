#include <stdio.h>
#include <iostream>

using namespace std;

int n;
long long s;

int main(void)
{
	int i,x,p,c=0;
	scanf("%d",&n);
	s=0;
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		if(!i||x!=p) {
			s+=(long long)c*(c+1)/2;
			c=0;
		}
		c++;
		p=x;
	}
	s+=(long long)c*(c+1)/2;
	cout << s << endl;
}