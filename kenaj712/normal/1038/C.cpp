#include<bits/stdc++.h>
using namespace std;
int taba[1000005];
int tabb[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    long long b=0,c=0;
    for(int x=0;x<a;x++)
        cin>>taba[x];
    for(int x=0;x<a;x++)
        cin>>tabb[x];
    sort(taba,taba+a);
    sort(tabb,tabb+a);
    int kon1=a-1,kon2=a-1,licz=0;
    while(licz<2*a)
    {
        if(licz%2==0)
        {
            if(kon1>-1&&kon2>-1)
            {
                if(taba[kon1]>tabb[kon2])
                {
                    b+=taba[kon1];
                    kon1--;
                }
                else
                    kon2--;
            }
            else
            {
                if(kon1==-1)
                    kon2--;
                else
                {
                    b+=taba[kon1];
                    kon1--;
                }
            }
        }
        else
        {
            if(kon1>-1&&kon2>-1)
            {
                if(tabb[kon2]>taba[kon1])
                {
                    c+=tabb[kon2];
                    kon2--;
                }
                else
                    kon1--;
            }
            else
            {
                if(kon2==-1)
                    kon1--;
                else
                {
                    c+=tabb[kon2];
                    kon2--;
                }
            }
        }
       // cout<<b<<" "<<c<<'\n';
        licz++;
    }
    cout<<b-c;
	return 0;
}