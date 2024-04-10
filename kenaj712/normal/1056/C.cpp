#include<bits/stdc++.h>
using namespace std;
int para[2005];
bool odw[2005];
int power[2005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d,turn,t,last=0;
    cin>>a>>b;
    a*=2;
    t=a;
    for(int x=1;x<=a;x++)
        cin>>power[x];
    for(int x=0;x<b;x++)
    {
        cin>>c>>d;
        para[c]=d;
        para[d]=c;
    }
    cin>>turn;
    turn%=2;
    while(t--)
    {
        if(turn==0)
        {
            cin>>c;
            last=c;
            odw[c]=true;
        }
        else
        {
            bool czy=false;
            if(para[last]!=0)
            {
                d=para[last];
                if(odw[d]==false)
                {
                    cout<<d<<'\n';
                    odw[d]=true;
                    czy=true;
                    cout.flush();
                }
            }
            if(czy==false)
            {
                for(int x=1;x<=a;x++)
                {
                    if(para[x]!=0&&odw[x]==false&&power[x]>power[para[x]])
                    {
                        cout<<x<<'\n';
                        odw[x]=true;
                        czy=true;
                        cout.flush();
                        break;
                    }
                }
                if(czy==false)
                {
                    int c=0,d=0;
                    for(int x=1;x<=a;x++)
                    {
                        if(odw[x]==false&&power[x]>c)
                        {
                            c=power[x];
                            d=x;
                        }
                    }
                    cout<<d<<'\n';
                    odw[d]=true;
                    czy=true;
                    cout.flush();
                }
            }
        }
        turn=(turn+1)%2;
    }
    return 0;
}