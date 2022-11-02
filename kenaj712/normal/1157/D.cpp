#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,c,d,e;
    cin>>a>>b;
    if(a==4&&b==2)
    {
        cout<<"NO";
        return 0;
    }
    if(b==1)
    {
        cout<<"YES"<<'\n'<<a;
        return 0;
    }
    if(b*(b+1)/2>a)
    {
        cout<<"NO";
        return 0;
    }
    c=a-(b*(b+1)/2);
    d=c%b;
    e=c/b;
    if(b==3&&d==b-1&&e==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    if(d!=b-1||e!=0)
    {
        for(int x=1;x<=b;x++)
        {
            if(x==b)
                cout<<x+d+e<<" ";
            else
                cout<<x+e<<" ";
        }
    }
    else
    {
        for(int x=1;x<=b;x++)
        {
            if(x==b)
                cout<<x+d+e-1<<" ";
            else if(x==b-1)
                cout<<x+e+1<<" ";
            else
                cout<<x+e<<" ";
        }
    }
	return 0;
}