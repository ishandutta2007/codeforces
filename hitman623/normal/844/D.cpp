#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    long n,start,x,i,ans=-1,in,r,val,next;
    cin>>n>>start>>x;
    in=start;
	srand(time(NULL));
    for(i=0;i<1000;++i)
    {
        r=(1LL*rand()*rand())%n+1;
        cout<<"? "<<r<<endl;
        fflush(stdout);
        cin>>val>>next;
        if(val>x) continue;
        if(ans<val) {ans=val,in=r;}
    }
    i=0;
    while(i<990)
    {
        i++;
        cout<<"? "<<in<<endl;
        fflush(stdout);
        cin>>val>>next;
        if(val>=x)
        {cout<<"! "<<val;fflush(stdout);exit(0);}
        in=next;
        if(in==-1)
        {
            cout<<"! "<<-1;
            fflush(stdout);
            exit(0);
        }
    }
    return 0;
}