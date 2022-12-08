#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int pr[N], pc[N];
typedef pair<int, int> pos;
typedef pair<pos, pos> door;

vector<door> ret;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &pr[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &pc[i]);
	for(int i=n;i;i--){
		if(pr[i]==i && pc[i]==i)continue;
		for(int j=1;j<i;j++)if(pr[j]==i)pr[j]=pr[i];
		for(int j=1;j<i;j++)if(pc[j]==i)pc[j]=pc[i];
		ret.push_back(door(pos(pr[i],i),pos(i,pc[i])));
	}
	cout << ret.size() << endl;
	for(size_t i=0;i<ret.size();i++){
		printf("%d %d %d %d\n",ret[i].first.first,ret[i].first.second,ret[i].second.first,ret[i].second.second);
	}
}