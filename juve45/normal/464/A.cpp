#include <iostream>
#define dmax 1004
using namespace std;

int n, p;
char s[dmax];

void buildback(int k)
{
    if(k==n+2)
    {
        for(int i=2;i<=n+1;i++)
        cout<<s[i];
        return;
    }
    for(int i='a';i<'a'+p;i++)
    {
        if(i!=s[k-1] && i!=s[k-2])
        {
            s[k]=i;
        buildback(k+1);
        return;
        }
    }

}

void solve()
{
    int ok=0;
    int j=n+1;

    while(!ok && j>=2)
    {
        for(char i=s[j]+1;i<'a'+p;i++)
        {
            if(i!=s[j-1] && i!=s[j-2])
            {
                ok=1;
                s[j]=i;
                buildback(j+1);
                return;
            }
        }
        j--;
    }
    cout<<"NO\n";
}

int main()
{
cin>>n>>p;

for(int i=2;i<=n+1;i++)
    cin>>s[i];
solve();
    return 0;
}