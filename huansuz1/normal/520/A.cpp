#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>

using namespace std;
string s;
int a[123],b[123],n;

int main(){
cin>>n;
cin>>s;
for (int i=0; i<s.length(); i++){
	if (s[i]>='a' && s[i]<='z')a[s[i]-'a']=1; else a[s[i]-'A']=1;
}
for (int i=0; i<26; i++)
	if (a[i]==0)  {cout<<"NO"; exit(0);}
	cout<<"YES";

}