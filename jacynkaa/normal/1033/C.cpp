#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<math.h>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define double long double
#define fi first
#define se second
const int stala=100006;
vector <int> X;

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    int n;
    cin>>n;
    X.resize(n);
    vector <int> pozycje (n+1);
    vector <char> Q (n,'B');

    for (int i=0; i<n; i++)
    {
        cin>>X[i];
        pozycje[X[i]]=i;
    }

    for (int i=n; i>0; i--)
    {
        int a=pozycje[i];
        for(int j=i; j<=n; j=j+i)
        {
            if(a-j>=0 && X[a-j]>i && Q[a-j]=='B')
                Q[a]='A';
            if(a+j<n && X[a+j]>i && Q[a+j]=='B')
                Q[a]='A';
        }
    }
    for (int i=0;i<n;i++)
    cout <<Q[i];
    cout <<endl;
    }