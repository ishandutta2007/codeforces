#include<bits/stdc++.h>
using namespace std;
struct stu{
	int rate , index , sco;
}ans[2001];
bool cmp1(stu a , stu b){
	return a.rate > b.rate;
}
bool cmp2(stu a , stu b){
	return a.index < b.index;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N;
	cin >> N;
	for(int i = 1 ; i <= N ; i++)
	{
		cin >> ans[i].rate;
		ans[i].index = i;
	}
	sort(ans + 1 , ans + N + 1 , cmp1);
	for(int i = 1 ; i <= N ; i++)
		if(ans[i].rate ^ ans[i - 1].rate)	ans[i].sco = i;
		else	ans[i].sco = ans[i - 1].sco;
	sort(ans + 1 , ans + N + 1 , cmp2);
	for(int i = 1 ; i <= N ; i++)	cout << ans[i].sco << ' ';
    return 0;
}