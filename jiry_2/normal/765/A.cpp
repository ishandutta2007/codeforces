#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
string s;
int num=0;
int main(){
	int n; scanf("%d",&n);
	cin>>s;
	for (;n;n--){
		string k1; cin>>k1;
		string k2=k1.substr(0,3);
		string k3=k1.substr(5,3);
		if (k2==s) num++; else num--;
	}
	if (num==0) cout<<"home"<<endl;
	else cout<<"contest"<<endl;
}