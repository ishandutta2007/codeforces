/*
K.D. Vinit
*/
#include <iostream>
using namespace std;

void solve()
{
    int n,same=0,freq[4]={0};
    cin>>n;

    string a,b;
    cin>>a>>b;

    cout<<"YES"<<endl;

    if(a[0]==a[1]) same++;
    if(b[0]==b[1]) same++;
    
    freq[a[0]-96]++;
    freq[a[1]-96]++;
    freq[b[0]-96]++;
    freq[b[1]-96]++;
    
    int flag=0;
    if(freq[1]==0 || freq[2]==0 || freq[3]==0) flag=1;

    if(same==2)
    {
        for(int i=1;i<=n;i++) cout<<"abc";
        cout<<endl;
        return;
    }
    if(same==1)
    {
        char x,y,p,q,r;
        if(a[0]==a[1]) { x=b[0]; y=b[1]; }
        else { x=a[0]; y=a[1]; }

        if(x=='a' && y=='b') { p='b'; q='a'; r='c'; }
        else if(x=='b' && y=='c') { p='c'; q='b'; r='a'; }
        else if(x=='c' && y=='a') { p='a'; q='c'; r='b'; }
        else if(x=='c' && y=='b') { p='b'; q='c'; r='a'; }
        else if(x=='b' && y=='a') { p='a'; q='b'; r='c'; }
        else  { p='c'; q='a'; r='b'; }

        for(int i=1;i<=n;i++) cout<<p<<q<<r;
        cout<<endl;
        return;
    }
    if(same==0 && flag==0)
    {
        char x,y,z;
        if(a[0]==b[0])
        {
            x=a[1];
            y=b[1];
            z=a[0];
        }
        else if(a[1]==b[1])
        {
            x=a[1];
            y=b[0];
            z=a[0];
        }
        else if(a[0]==b[1])
        {
            x=a[1];
            y=a[0];
            z=b[0];
        }
        else
        {
            x=b[1];
            y=a[1];
            z=a[0];
        }

        for(int i=1;i<=n;i++) cout<<x;
        for(int i=1;i<=n;i++) cout<<y;
        for(int i=1;i<=n;i++) cout<<z;
        cout<<endl;
        return;
    }
    else
    {
        char x,y,z;
        x=a[0];
        y=a[1];

        if(x=='a' && y=='b') z='c';
        else if(x=='b' && y=='c') z='a';
        else if(x=='c' && y=='a') z='b';
        else if(x=='c' && y=='b') z='a';
        else if(x=='b' && y=='a') z='c';
        else z='b';
        
        for(int i=1;i<=n;i++) cout<<x;
        for(int i=1;i<=n;i++) cout<<z;
        for(int i=1;i<=n;i++) cout<<y;
        cout<<endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}