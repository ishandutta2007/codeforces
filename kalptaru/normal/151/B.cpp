 
 #include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string r[n];
    pair<int,int> a[n],b[n],c[n];
    for(int i=0;i<n;i++)
    {
        int k;
        string s;
        cin>>k>>s;
        r[i]=s;
        a[i].first=0; a[i].second=n-i;
        b[i].first=0; b[i].second=n-i;
        c[i].first=0; c[i].second=n-i;
        for(int j=0;j<k;j++)
        {
            string z;
            cin>>z;
            if(z[0]==z[1]&&z[0]==z[3]&&z[0]==z[4]&&z[0]==z[6]&&z[0]==z[7])
                a[i].first++;
            else if(z[0]>z[1]&&z[1]>z[3]&&z[3]>z[4]&&z[4]>z[6]&&z[6]>z[7])
                b[i].first++;
            else c[i].first++;
        }
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    cout<<"If you want to call a taxi, you should call: "<<r[n-a[n-1].second];
    for(int i=n-2;i>=0;i--)
    {
        if(a[n-1].first==a[i].first)
            cout<<", "<<r[n-a[i].second];
    }
    cout<<"."<<endl;
    cout<<"If you want to order a pizza, you should call: "<<r[n-b[n-1].second];
    for(int i=n-2;i>=0;i--)
    {
        if(b[n-1].first==b[i].first)
            cout<<", "<<r[n-b[i].second];
    }
    cout<<"."<<endl;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: "<<r[n-c[n-1].second];
    for(int i=n-2;i>=0;i--)
    {
        if(c[n-1].first==c[i].first)
            cout<<", "<<r[n-c[i].second];
    }
    cout<<"."<<endl;
}