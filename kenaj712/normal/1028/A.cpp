#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d,e,f;
    char znak;
    bool czy=false;
    cin>>a>>b;
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        {
            cin>>znak;
            if(znak=='B')
            {
                e=x;
                f=y;
                if(czy==false)
                {
                    c=x;
                    d=y;
                    czy=true;
                }
            }
        }
    cout<<(c+e)/2<<" "<<(d+f)/2;
	return 0;
}