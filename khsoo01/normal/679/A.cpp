#include<bits/stdc++.h>
using namespace std;
bool np[105];
vector<int> p;

int main()
{
	np[1] = true;
	for(int i=2;i<=50;i++) {
		if(!np[i]) {
			for(int j=i*i;j<=50;j+=i) {
				np[j] = true;
			}
			p.push_back(i);
		}
	}
	int cnt = 0;
	for(auto &T : p) {
		printf("%d\n",T);
		fflush(stdout);
		char x[10];
		scanf("%s",x);
		cnt += (x[0] == 'y');
		if(cnt >= 2) {puts("composite"); return 0;}
	}
	for(int i=2;i<=10;i++) {
		if(np[i]) continue;
		printf("%d\n",i*i);
		fflush(stdout);
		char x[10];
		scanf("%s",&x);
		if(x[0] == 'y') {puts("composite"); return 0;}
	}
	puts("prime");
}