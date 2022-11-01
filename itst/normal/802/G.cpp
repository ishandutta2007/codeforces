#include<bits/stdc++.h>
using namespace std;
string s , ex = "heidi";
bool sear(int i , int dir)
{
	if(i == ex.size())
		return true;
	if(dir == s.size())
		return false;
	if(s[dir] == ex[i])
		return sear(i + 1 , dir + 1);
	else
		return sear(i , dir + 1);
}
int main(){
	cin >> s;
	if(sear(0 , 0))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}