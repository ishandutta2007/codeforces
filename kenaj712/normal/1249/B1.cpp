#include<bits/stdc++.h>
using namespace std;
int lider[1000005];
int ile[1000005];
int f(int a)
{
    if(lider[a]==a)
        return a;
    else
    {
        lider[a]=f(lider[a]);
        return lider[a];
    }
}
void u(int a,int b)
{
    lider[f(a)]=f(b);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,c;
        cin>>a;
        for(int x=1;x<=a;x++)
        {
            lider[x]=x;
            ile[x]=0;
        }
        for(int x=1;x<=a;x++)
        {
            cin>>c;
            u(x,c);
        }
        for(int x=1;x<=a;x++)
            ile[f(x)]++;
        for(int x=1;x<=a;x++)
        {
            cout<<ile[f(x)]<<" ";
        }
        cout<<'\n';
    }
	return 0;
}