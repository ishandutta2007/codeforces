// Hydro submission #6254fe23ac286d0a56b85193@1649737252441
#include<bits/stdc++.h>
using namespace std;
string c;int t[26],s;
int main()
{
	getline(cin,c);int i;
	for(i=0;i<c.size();i++)
	if(c[i]>96&&c[i]<123)
	t[c[i]-97]++;
	for(i=0;i<26;i++)
	if(t[i]) s++;
	printf("%d\n",s);
    return 0;
}