// Hydro submission #62cd088e4125dc528b1ce22b@1657604239236
#include<bits/stdc++.h>
using namespace std;
int main()
{
string s,res;
cin>>s;
for(int i = 0;i<s.length();i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]=s[i]+32;
		}
		if(s[i]!='a'&&s[i]!='o'&&s[i]!='y'&&s[i]!='e'&&s[i]!='u'&&s[i]!='i'){
			res+='.';
			res+=s[i];	
		}
}

cout<<res;
}