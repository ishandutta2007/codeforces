#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans1,ans2;
	ans1 = n/7;
	ans1*=2;
	ans2 = ans1;
	switch(n%7){
	case 0: ans2+=0; break;
	case 1: ans2+=1; break;
	case 2:case 3:case 4:case 5: ans2+=2; break;
	case 6: ans2+=2; ans1+=1; break;
	}
	cout << ans1 << " " << ans2;
	return 0;
}