#include<bits/stdc++.h>
using namespace std;
struct leaf{
	string tree , color;
}pick[101];
bool cmp(const leaf &a , const leaf &b)
{
	if(a.tree == b.tree)	return a.color < b.color;
	return a.tree < b.tree;
}
int main(){
	int n , num = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> pick[i].tree >> pick[i].color;
	sort(pick , pick + n , cmp);
	for(int i = 0 ; i < n ; i++)
		if(!i || pick[i].tree != pick[i - 1].tree || pick[i].color != pick[i - 1].color)
			num++;
	cout << num;
	return 0;
}