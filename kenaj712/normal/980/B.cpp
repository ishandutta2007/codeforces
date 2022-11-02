#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
        cout<<"YES"<<'\n';
        if(b%2!=0&&b>=a-2)
        {
            b=b-a+2;
            for(int x=1;x<=4;x++)
            {
                for(int y=1;y<=a;y++)
                {
                    if((x==2||x==3)&&y!=1&&y!=a&&((x==2)||(y<=b/2+1||y>=a-b/2)))
                        cout<<"#";
                    else
                        cout<<".";
                }
                cout<<'\n';
            }
        }
        else if(b%2==0)
            for(int x=1;x<=4;x++)
            {
                for(int y=1;y<=a;y++)
                {
                    if((x==2||x==3)&&(y!=1&&y!=a)&&y-1<=b/2)
                        cout<<"#";
                    else
                        cout<<".";
                }
                cout<<'\n';
            }
        else
        {
            b=a-2-b;
            for(int x=1;x<=4;x++)
            {
                for(int y=1;y<=a;y++)
                {
                    if((x==2||x==3)&&y!=1&&y!=a&&x==2&&(y>b/2+1&&y<a-b/2))
                        cout<<"#";
                    else
                        cout<<".";
                }
                cout<<'\n';
            }
        }
	return 0;
}