#include<bits/stdc++.h>
using namespace std;
int tab[105];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        int b;
        cin>>b;
        for(int y=0;y<20;y++)
        {
            tab[y]+=b%2;
            b/=2;
        }
    }
    long long sum=0;
    for(int x=0;x<a;x++)
    {
        long long xd=0;
        for(int y=0;y<20;y++)
            if(tab[y]>0)
            {
                xd+=(1<<y);
                tab[y]--;
            }
        sum+=xd*xd;
    }
    cout<<sum;
	return 0;
}