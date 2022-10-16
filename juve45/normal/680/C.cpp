#include <bits/stdc++.h>

using namespace std;

vector <int> v;

bool prime(int k)
{
    for(int i=2; i*i<=k; i++)
    {
        if(k%i==0)
            return false;
    }
    return true;
}


int main()
{
    int ans=0;
    string s;
    for(int i=2; i<=100; i++)
    {
        if(prime(i))
            v.push_back(i);
    }
    int m=1;
    int ok=0;
    for(int i=0; m*v[i]<=100; i++)
    {
    if(ok==0 && v[i]>50)
    {cout<<"prime\n";
    return 0;
    }
        cout<<m*v[i]<<'\n';
        fflush(stdout);
        cin>>s;
        if(ok==1)
        {
            if(s=="yes")
            {

                cout<<"composite\n";
                return 0;
            }
        }
        else if(s=="yes")
        {
            ok=1;
            m=v[i];
            i--;
        }
    }
    cout<<"prime\n";
    return 0;
}