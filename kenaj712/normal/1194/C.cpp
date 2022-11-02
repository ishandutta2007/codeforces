#include<bits/stdc++.h>
using namespace std;
int tab1[29];
int tab2[29];
int f(char a)
{
    return int(a)-97;
}
void czysc()
{
    for(int x=0;x<=26;x++)
    {
        tab1[x]=0;
        tab2[x]=0;
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        czysc();
        int pom1=0,pom2=0;
        while(pom1<a.size()&&pom2<b.size())
        {
            if(a[pom1]==b[pom2])
            {
                pom1++;
                pom2++;
            }
            else
            {
                tab1[f(b[pom2])]++;
                pom2++;
            }
        }
        for(int x=pom2;x<b.size();x++)
            tab1[f(b[x])]++;
        if(pom1!=a.size())
        {
            cout<<"NO"<<'\n';
            continue;
        }
        for(auto x:c)
            tab2[f(x)]++;
        bool czy=false;
        for(int x=0;x<26;x++)
        {
            if(tab1[x]>tab2[x])
            {
                cout<<"NO"<<'\n';
                czy=true;
                break;
            }
        }
        if(czy==false)
            cout<<"YES"<<'\n';
    }
	return 0;
}