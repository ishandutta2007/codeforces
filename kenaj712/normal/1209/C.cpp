#include<bits/stdc++.h>
using namespace std;
bool mark[1000005];
void czysc(int a)
{
    for(int x=0;x<a;x++)
        mark[x]=false;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        string d;
        cin>>a>>d;
        bool wtf=false;
        for(char x='0';x<='9';x=char(int(x)+1))
        {
            char maks='0';
            bool czy=false;
            string xd="";
            int licz=0;
            for(auto y:d)
            {
                if(y<x)
                {
                    if(y<maks)
                        czy=true;
                    else
                        maks=y;
                }
                if(y==x)
                    licz++;
            }
            maks='0';
            for(auto y:d)
            {
                if(y>x)
                {
                    if(y<maks)
                    {
                        czy=true;
                    }

                    else
                        maks=y;
                }
            }
            for(int y=d.size()-1;y>=0;y--)
            {
                if(d[y]==x)
                    licz--;
                if(d[y]<x)
                    break;
            }
            for(int y=0;y<a;y++)
            {
                if(d[y]==x)
                    licz--;
                if(d[y]>x)
                    break;
            }
            if(licz>0)
                czy=true;
            if(czy==false)
            {
                int sf=0;
                for(auto y:d)
                {
                    if(y<x)
                        xd.push_back('1');
                    else if(y>x)
                    {
                        xd.push_back('2');
                        sf++;
                    }
                    else
                    {
                        if(sf==0)
                            xd.push_back('2');
                        else
                            xd.push_back('1');
                    }
                }
                cout<<xd<<'\n';
                wtf=true;
                break;
            }

        }
        if(wtf==false)
            cout<<"-"<<'\n';
    }
	return 0;
}