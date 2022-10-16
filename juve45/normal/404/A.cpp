#include <iostream>
#include <cstring>
using namespace std;
int n;
char s[303][303];

int main()
{
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++)
        cin.getline(s[i], 303);
    char c, d;
    c=s[0][0];
    d=s[0][1];

    if(c==d)
    {
        cout<<"NO";
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        if(s[i][i]!=c || s[i][n-i-1]!=c)
        {
            cout<<"NO";
            return 0;
        }

        s[i][i]=d;
        s[i][n-i-1]=d;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(s[i][j]!=d)
            {
                cout<<"NO";
                return 0;
            }

    cout<<"YES";
    return 0;

}