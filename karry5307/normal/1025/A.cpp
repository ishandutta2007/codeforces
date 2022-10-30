#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll len,appear[256];
string str;
bool has_solution; 
int main()
{
	cin>>len>>str;
	for(register int i=0;i<str.length();i++)
	{
		appear[(ll)(str[i])]++;
	}
	for(register char i='a';i<='z';i++)
	{
		if(appear[(ll)(i)]>=2||str.length()==1)
		{
			has_solution=1;
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}