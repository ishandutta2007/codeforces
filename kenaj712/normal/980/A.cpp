#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    int pom1=0,pom2=0;
    for(int x=0;x<a.size();x++)
        {
            if(a[x]=='o')
            pom1++;
            else
                pom2++;
        }
    if(pom1==0)
        cout<<"YES";
    else
    {
        if(pom2%pom1==0)
        cout<<"YES";
    else
        cout<<"NO";
    }

	return 0;
}