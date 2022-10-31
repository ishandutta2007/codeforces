// Hydro submission #6253d4c9ca53060146717596@1649661134965
#include<bits/stdc++.h>
using namespace std;
string s,r;
int t=0,u=0;
int main(){
	cin>>s>>r;
	for(int i=0;i<s.size();i+=2)
	{
		if(s[i]==r[i]) continue;
        if((s[i]=='('&&r[i]=='8')
		||(s[i]=='8'&&r[i]=='[')
	    ||(s[i]=='['&&r[i]=='(')) t++;
	    else u++;
	}
	if(t>u) printf("TEAM 1 WINS\n");
	else if(t<u) printf("TEAM 2 WINS\n");
	else printf("TIE\n");
	return 0;
}