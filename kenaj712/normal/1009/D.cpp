#include<bits/stdc++.h>
using namespace std;
int nwd(int a,int b)
{
    while(a!=0&&b!=0)
    {
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    if(a==0)
        return b;
    else
        return a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b;
	cin>>a>>b;
    if(b+1<a||a*(a-1)/2<b)
        cout<<"Impossible";
    else
    {
        long long pom=b;
        for(int x=1;x<=a;x++)
            for(int y=x+1;y<=a;y++)
            {
                if(pom==0)
                    break;
                if(nwd(x,y)==1)
                    pom--;

            }
        if(pom!=0)
            cout<<"Impossible";
        else
        {
            pom=b;
            cout<<"Possible"<<'\n';
            for(int x=1;x<=a;x++)
            for(int y=x+1;y<=a;y++)
            {
                if(pom==0)
                    break;
                if(nwd(x,y)==1)
                {
                    pom--;
                    cout<<x<<" "<<y<<'\n';
                }


            }
        }

    }



	return 0;
}