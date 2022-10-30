#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,cur,res;
string s;

int main() {
	cin>>s;
	for(auto i:s){
		if(i=='M')k++,cur=max(0,cur-1);
		else if(k)res=max(res,cur+k),cur++;
	}
	cout<<res;
}