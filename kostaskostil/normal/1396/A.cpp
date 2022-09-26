#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=1e6+100;
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int qqq;
//    cin>>qqq;
//    for (int iii=0; iii<qqq; iii++)
//    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i:v) cin>>i;
        if (n==1)
        {
            cout<<"1 1\n0\n1 1\n0\n1 1\n"<<-v[0]<<"\n";
            return 0;
        }
        cout<<1<<" "<<1<<"\n";
        cout<<-v[0]<<"\n";
        v[0]=0;
        cout<<2<<" "<<n<<"\n";
        for (int i=1; i<n; i++)
        {
            cout<<(n-1)*v[i]<<" ";
            v[i]+=(n-1)*v[i];
        }
        cout<<"\n";
        cout<<1<<" "<<n<<"\n";
        for (int i=0; i<n; i++)
            cout<<-v[i]<<" ";
        cout<<"\n";
//    }
}