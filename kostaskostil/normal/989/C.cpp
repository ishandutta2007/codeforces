#include <bits/stdc++.h>

using namespace std;

int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;
    b--;
    cout<<"50 50\n";
    for (int i=1; i<=24; i++)
    {
        for (int j=1; j<=50; j++)
    {
        if ((j%2==0) or (i%2==0))
            cout<<"A";
        else
        {
        if (b>0)
            cout<<"B",b--;
        else
        if (c>0)
            cout<<"C",c--;
        else
        if (d>0)
            cout<<"D",d--;
        else
            cout<<"A";
        }
    }
    cout<<"\n";
    }
    for (int i=25; i<=50; i++)
    {
        for (int j=1; j<=50; j++)
    {
        if ((j%2==1) or (i%2==1))
            cout<<"B";
        else
        {
        if (a>0)
            cout<<"A",a--;
        else
            cout<<"B";
        }
    }
    cout<<"\n";
    }

//    int s[2010];
//    cin>>n>>p;
//    for (int i=1; i<=n; i++)
//    {
//        char t;
//        cin>>t;
//        if (t=='1')
//            s[i]=1;
//        if (t=='0')
//            s[i]=0;
//        if (t=='.')
//            s[i]=-1;
//    }
//    for (int i=1; i<=n; i++)
//    {
//        if (s[i]!=-1)
//        {
//            for (int j=1; i-j*p>0; j++)
//            {
//                if ((s[i-j*p]==-1) or (s[i-j*p]==s[i-j*p+p]))
//                    s[i-j*p]=s[i-j*p+p];
//                else
//                {
//                    cout<<"No\n";
//                    exit(0);
//                }
//            }
//            for (int j=1; i+j*p<=n; j++)
//            {
//                if ((s[i+j*p]==-1) or (s[i+j*p]==s[i+j*p-p]))
//                    s[i+j*p]=s[i+j*p-p];
//                else
//                {
//                    cout<<"No\n";
//                    exit(0);
//                }
//            }
//        }
//    }
//    for (int i=1; i<=n; i++)
//    {
//        if (s[i]>=0)
//            cout<<s[i];
//        else
//            cout<<1";
//    }
    return 0;
}