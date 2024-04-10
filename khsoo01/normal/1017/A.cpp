#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

const int N = 1005;

int n;

pair<int,int> a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int A,B,C,D;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		a[i] = {-A-B-C-D,i};
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		if(a[i].Y == 1) {
			printf("%d\n",i);
			return 0;
		}
	}
}