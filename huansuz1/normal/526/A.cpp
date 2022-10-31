#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
 int n;
 set<int> s;
 string c;

int main(){
 cin>>n>>c;
 for (int i=0;i<c.size();i++)
 	if (c[i]=='*') s.insert(i);
 for (set<int>::iterator it = s.begin();it!=s.end();it++) {
 	for (int i=1;i<c.size();i++) {
 	int qw=0;
	int el=*it;
 while (s.find(el+i)!=s.end()) {
 qw++;
 el+=i;
 }
 if (qw>3){
 cout<<"yes";
 exit(0);
 }
 }
 }
 cout<<"no";
 }