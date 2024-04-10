// Hydro submission #6274ce70bda16328ffbafc77@1651822192868
#include<bits/stdc++.h>
#define do if(work()){printf("YES\n");continue;}
using namespace std;
bool f;string c;
int m[3],j,l,s;
bool work()
{
    s=0,f=true;
	for(j=0;j<l;j++)
    {
		s+=m[c[j]];
		if(s<0)
        {
            f=false;
            break;
        }
	}
    return f&&!s;
}
int main()
{
	int t,p,i;
    cin>>t;
	for(i=0;i<t;i++)
    {
		cin>>c;l=c.size();
		if(l%2||c[0]==c[l-1])
        {
            printf("NO\n");
            continue;
        } 
        m[0]=0,m[1]=0,m[2]=0;
        for(j=0;j<l;j++)
        c[j]-=65;
		m[c[0]]=1;
		m[c[l-1]]=-1;
		for(j=0;j<3;j++)
        if(!m[j]) p=j;
		m[p]=1;do
		m[p]=-1;do
		printf("NO\n");
	}
	return 0;
}