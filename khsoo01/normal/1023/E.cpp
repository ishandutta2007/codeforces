#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

int n;

char ipt[5];

vector<pii> bw, fw;

int main()
{
	scanf("%d",&n);
	int X = n, Y = n;
	for(int i=1;i<n;i++) {
		bw.push_back({X, Y});
		printf("? 1 1 %d %d\n", X-1, Y);
		fflush(stdout);
		scanf("%s", ipt);
		if(ipt[0] == 'Y') X--;
		else Y--;
	}
	X = 1, Y = 1;
	for(int i=1;i<n;i++) {
		fw.push_back({X, Y});
		printf("? %d %d %d %d\n", X, Y+1, n, n);
		fflush(stdout);
		scanf("%s", ipt);
		if(ipt[0] == 'Y') Y++;
		else X++;
	}
	fw.push_back({X, Y});
	while(!bw.empty()) {
		fw.push_back(bw.back());
		bw.pop_back();
	}
	printf("! ");
	for(int i=1;i<(int)fw.size();i++) {
		if(fw[i].X == fw[i-1].X) putchar('R');
		else putchar('D');
	}
}