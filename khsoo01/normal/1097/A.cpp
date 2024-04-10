#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

char a[5];

int main()
{
	scanf("%s",a);
	for(int i=0;i<5;i++) {
		char b[5];
		scanf("%s",b);
		if(a[0] == b[0] || a[1] == b[1]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}