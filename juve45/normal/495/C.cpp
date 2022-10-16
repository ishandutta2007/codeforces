#include <iostream>
#include <cstring>

#define dmax 100005
using namespace std;


char s[dmax];
int c[dmax], ans;
int n1, n2;

int main()
{
    cin>>s;
    int n=strlen(s);

    if(s[0]=='(')
        c[0]=1, n1++;
    else
    {
        cout << -1 << '\n';
        return 0;
    }

    for(int i=1; i<n; i++)
    {
        if(s[i]=='(')
            c[i]=c[i-1]+1, n1++;
        else if(s[i]==')')
            c[i]=c[i-1]-1, n2++;
        else if(s[i]=='#')
            c[i]=c[i-1]-1, ans++;
    }

    for(int i=0; i<n; i++)
    {
        if(c[i]<0)
        {
            cout<<-1<<'\n';
            return 0;
        }

    }

    int ss=0;
    for(int i=n-1; i>=0 && s[i]!='#'; --i)
    {
        if(s[i]=='(')
            ss++;
        else if(s[i]==')')
            ss--;

        if(ss>0)
    {
        cout<<-1<<'\n';
        return 0;
    }
    }


    for(int i=1; i<ans; i++)
        cout<<"1\n";
    cout<<c[n-1]+1<<'\n';


    return 0;
}