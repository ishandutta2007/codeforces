#include<bits/stdc++.h>
using namespace std;
set<string>st;
string str;
int cnt;
int main()
{
	cin>>cnt;
	getline(cin,str);
	for(register int i=0;i<cnt;i++)
	{
		getline(cin,str);
		st.insert(str);
	}
	cout<<st.size();
}