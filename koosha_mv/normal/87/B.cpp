#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> mp;
int work(string s)
{
	int i=0,j=s.size()-1,c1=0,c2=0;
	while (i<s.size() && s[i]=='&') i++,c1++;
	while (j>=0 && s[j]=='*') j--,c2++;
	string t=s.substr(i,j-i+1);
	int x=0;
	if (!mp.count(t)) return -1;
	else if (mp[t]<0) return mp[t];
	else x=mp[t];
	x+=c2-c1;
	return x;
}
int main()
{
	int n;
	cin >>n;
	mp["void"]=0;
	for (int xx=0;xx<n;xx++){
		string w;
		cin >>w;
		if (w=="typeof"){
			string s;
			cin >>s;
			int x=work(s);
			if (x<0) cout <<"errtype"<<"\n";
			else if (!x) cout <<"void"<<"\n";
			else{
				cout <<"void";
			    for (int i=0;i<x;i++) cout <<"*";
			    cout <<"\n";}
		}
		else{
			string a,b;
			cin >>a>>b;
			mp[b]=work(a);
		}
	}
	return 0;
}