#include <iostream>

using namespace std;

int n;


void solve1(int k)//even
{
    for(int i=k;i>4;i-=2)
    {cout<<i<<" - "<<i-1<<" = "<<1<<'\n';
    cout<<"1 * 1 = 1\n";
    }
    cout<<"1 * 2 = 2\n";
    cout<<"2 * 3 = 6\n";
    cout<<"6 * 4 = 24\n";
}

void solve2(int k)//ODD
{
    for(int i=k;i>7;i-=2)
    {cout<<i<<" - "<<i-1<<" = "<<1<<'\n';
    cout<<"1 * 1 = 1\n";
    }

    cout<<"1 - 2 = -1\n";
    cout<<"-1 + 3 = 2\n";
    cout<<"2 + 4 = 6\n";
    cout<<"6 + 5 = 11\n";
    cout<<"11 + 6 = 17\n";
    cout<<"17 + 7 = 24\n";

}

int main()
{
cin>>n;

if(n>=7)
{
    cout<<"YES\n";
    if(n%2==0)
        solve1(n);
    else solve2(n);

}
if(n==6 || n==4)
{
cout<<"YES\n";
    solve1(n);
}
if(n==5)
{
    cout<<"YES\n";
    cout<<"5 - 1 = 4\n";
    cout<<"4 - 2 = 2\n";
    cout<<"2 * 3 = 6\n";
    cout<<"6 * 4 = 24\n";
}
if(n==3 || n==2 || n==1)
{
    cout<<"NO\n";
}

    return 0;
}