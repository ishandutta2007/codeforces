#include<bits/stdc++.h>
using namespace std;
main(){
string s;
cin>>s;
int n=size(s);
int z=remove(begin(s),end(s),49)-begin(s);
s.insert(~s.find(50)?s.find(50):z,n-z,49);
cout<<s.substr(0,n);
}