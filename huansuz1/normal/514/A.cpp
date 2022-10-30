#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

 using namespace std;
 string s,t="0123456789";
 int main(){
    cin>>s;
    for (int i=0; i<s.length(); i++)
    	if (s[i]-'0'>=5 && i==0 && s[i]-'0'<9) s[i]=t[9-(s[i]-'0')]; else 
    		  	if (s[i]-'0'>=5 && i!=0) s[i]=t[9-(s[i]-'0')];  
    cout<<s;
	
	return 0;
 }