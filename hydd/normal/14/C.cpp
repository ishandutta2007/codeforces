#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<pii,int> mp; int x,y;
bool check(){
	if (mp.size()!=4||x!=2||y!=2) return false;
	for (auto v:mp)
		if (v.second!=2) return false;
	return true;
}
int main(){
	int x1,y1,x2,y2;
	for (int i=1;i<=4;i++){
		cin>>x1>>y1>>x2>>y2;
		x+=(x1==x2&&y1!=y2); y+=(x1!=x2&&y1==y2);
		mp[pii(x1,y1)]++; mp[pii(x2,y2)]++;
	}
	if (check()) puts("YES");
	else puts("NO");
	return 0;
}