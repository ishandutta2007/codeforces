#include<bits/stdc++.h>
using namespace std;

int n, cc;
char a[200005];

vector<int> zeb[200005];

queue<int> o, z;

int main()
{
	scanf("%s",a+1);
	n = strlen(a+1);
	for(int i=1;i<=n;i++) {
		if(a[i] == '0') {
			if(!o.empty()) {
				int T = o.front(); o.pop();
				zeb[T].push_back(i);
				z.push(T);
			}
			else {
				++cc;
				zeb[cc].push_back(i);
				z.push(cc);
			}
		}
		else {
			if(!z.empty()) {
				int T = z.front(); z.pop();
				zeb[T].push_back(i);
				o.push(T);
			}
			else {puts("-1"); return 0;}
		}
	}
	if(!o.empty()) {puts("-1"); return 0;}
	printf("%d\n",cc);
	for(int i=1;i<=cc;i++) {
		printf("%d ",zeb[i].size());
		for(auto &T : zeb[i]) printf("%d ",T);
		puts("");
	}
}