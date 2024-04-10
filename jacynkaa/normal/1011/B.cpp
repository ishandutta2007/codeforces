#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    vector <int> X (200);

    for (int i=0; i<m; i++)
    {
        int a;
        cin>>a;
        X[a]++;
    }

    for (int odp=1; odp<=101; odp++)
    {
        int a=0;
        for (int i=0; i<150; i++)
            a+=(X[i]/odp);

        if(a<n)
        {
            cout <<odp-1<<endl;
            return 0;
        }
    }
}