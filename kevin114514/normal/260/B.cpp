#include<bits/stdc++.h>
using namespace std;
const int ds[]={31,28,31,30,31,30,31,31,30,31,30,31};
map<string,int> T;
int BT=-1;
string BS;
void valid(string s)
{
	if(s[2]!='-'||s[5]!='-')
		return ;
	for(int i=0;i<s.length();i++)
		if(i!=2&&i!=5&&s[i]=='-')
			return ;
	s[2]=' ';
	s[5]=' ';
	stringstream IN(s);
	int d,m,y;
	IN>>d>>m>>y;
	if(y<2013||y>2015||m<1||m>12||d<1||d>ds[m-1])
		return ;
	s[2]='-';
	s[5]='-';
	T[s]++;
	if(T[s]>BT)
		BS=s,
		BT=T[s];
	return ;
}
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length()-9;i++)
		valid(s.substr(i,10));
	cout<<BS;
	return 0;
}