#include<bits/stdc++.h>
using namespace std;
map <string,int> m;
int main(){
	m["monday"]=1;
	m["tuesday"]=2;
	m["wednesday"]=3;
	m["thursday"]=4;
	m["friday"]=5;
	m["saturday"]=6;
	m["sunday"]=7;
	string a,b;
	cin>>a>>b;//
	int x=m[a],y=m[b];
	if((y+7-x)%7==0||(y+7-x)%7==2||(y+7-x)%7==3) cout<<"YES";
	else cout<<"NO";
    cout<<endl;
	return 0; 
}