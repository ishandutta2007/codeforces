// Hydro submission #62677be09f31360077e12bb9@1650949089573
#include<bits/stdc++.h>
using namespace std;
string v[118]={"H","HE","LI","BE","B",
"C","N","O","F","NE","NA","MG","AL",
"SI","P","S","CL","AR","K","CA","SC",
"TI","V","CR","MN","FE","CO","NI","CU",
"ZN","GA","GE","AS","SE","BR","KR","RB",
"SR","Y","ZR","NB","MO","TC","RU","RH",
"PD","AG","CD","IN","SN","SB","TE","I",
"XE","CS","BA","LA","CE","PR","ND","PM",
"SM","EU","GD","TB","DY","HO","ER","TM",
"YB","LU","HF","TA","W","RE","OS","IR",
"PT","AU","HG","TL","PB","BI","PO","AT",
"RN","FR","RA","AC","TH","PA","U","NP",
"PU","AM","CM","BK","CF","ES","FM","MD",
"NO","LR","RF","DB","SG","BH","HS","MT",
"DS","RG","CN","NH","FL","MC","LV","TS","OG"},t;
bool f;
int main()
{
	cin>>t;
    int x,i;
	vector<bool>b(t.size()+1);
	b[0]=true;
	for(i=0;i<t.size();i++) if(b[i])
    for(string c:v)
    {
        x=c.size();
		if(t.substr(i,x)==c) b[i+x]=true;
	}
	printf(b.back()?"YES\n":"NO\n");
	return 0;
}