#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int licz1=0,licz2=0,licz3=0,pom,t,licz=0;
    cin>>t;
    string a;
    while(t--)
    {
        cin>>a;
        licz1=0,licz2=0,licz3=0;
        for(int x=0;x<a.size();x++)
        {
            if(a[x]=='(')
                licz3++;
            if(a[x]==')')
            {
                if(licz3==0)
                    licz1++;
                else
                    licz3--;
            }
        }
        licz2=licz3;
        if(licz1!=0&&licz2!=0)
            continue;
        else
        {
            pom=licz1-licz2;
            multiset<int>::iterator it=s.find(-pom);
            if(it==s.end())
                s.insert(pom);
            else
            {
                licz++;
                s.erase(it);
            }
        }
    }
    cout<<licz;

	return 0;
}