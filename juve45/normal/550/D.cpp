#include <iostream>
#include <cstdio>

using namespace std;
int n;


int main()
{
    //freopen("o.txt", "w", stdout);
    cin>>n;

    if(n%2==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    if(n==1)
    {
        cout << "2 1\n1 2";
        return 0;
    }

    cout << 2*n+4<<' '<< n*(n+2)<<'\n';

    int s1=1;
    int s2=n+3;

    for(int i=1; i<n; i++)
    {
        cout << s1 << ' ' << s1+i<<'\n';
        cout << s1+n << ' ' << s1+i<<'\n';
        cout << s1+n+1 << ' ' << s1+i<<'\n';
        cout << s2 << ' ' << s2+i<<'\n';
        cout << s2+n << ' ' << s2+i<<'\n';
        cout << s2+n+1 << ' ' << s2+i<<'\n';
    }

    for(int i=1; i<n-1; i++)
        for(int j=1; i+j<n; j++)
        {
            ////PROBLEM!!!!!!!!!!!!!!!
            if(i%2!=0 && j==1)continue;
            cout<<s1+i<<' '<<s1+i+j<<'\n';
            cout<<s2+i<<' '<<s2+i+j<<'\n';
        }

    cout<<s1<<' '<<s2<<'\n';
    cout<<s1+n<<' '<<s1+n+1<<'\n';
    cout<<s2+n<<' '<<s2+n+1<<'\n';

    return 0;
}