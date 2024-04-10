#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int>mp;
map<int,string>m;
string x;
int y;
int main()
{
	mp["January"]=1;mp["February"]=2;mp["March"]=3;mp["April"]=4;mp["May"]=5;mp["June"]=6;
	mp["July"]=7;mp["August"]=8;mp["September"]=9;mp["October"]=10;mp["November"]=11;mp["December"]=12;
	m[1]="January";m[2]="February";m[3]="March";m[4]="April";m[5]="May";m[6]="June";
	m[7]="July";m[8]="August";m[9]="September";m[10]="October";m[11]="November";m[12]="December";
	cin>>x>>y;
	y%=12;
	if((mp[x]+y)%12==0)
	{
		cout<<m[12];
		return 0;
	}
	cout<<m[(mp[x]+y)%12];
}