#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,p;
    cin>>a>>p;
    string d;
    cin>>d;
    bool czy=false;
    bool czy2=false;
    int pom=0;
    for(int x=0;x<a;x++)
    {
        if(x>=p)
            if((d[x-p]=='0'&&d[x]=='1')||(d[x]=='0'&&d[x-p]=='1'))
                czy=true;
        if(x>=p||a-1-p>=x)
            if(d[x]=='.')
            {
                czy2=true;
                pom=x;
            }
    }
    if(czy2==false&&czy==false)
        cout<<"No";
    else
    {
        if(czy==true)
        {
            for(int x=0;x<a;x++)
            {
                if(d[x]!='.')
                    cout<<d[x];
                else
                    cout<<0;
            }
        }
        else
        {
            for(int x=0;x<a;x++)
            {
                if(d[x]!='.')
                    cout<<d[x];
                else if(x!=pom)
                    cout<<0;
                else
                    {
                        if(x>=p)
                        {
                           if(d[pom-p]=='0'||d[pom-p]=='.')
                            cout<<1;
                        else
                            cout<<0;
                        }
                        else
                        {
                           if(d[pom+p]=='0')
                            cout<<1;
                        else
                            cout<<0;
                        }
                    }
            }
        }
    }
	return 0;
}