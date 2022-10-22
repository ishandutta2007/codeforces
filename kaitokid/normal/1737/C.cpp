#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r[3],c[3];
int x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int hx=-1,hy=-1;
        for(int i=0;i<3;i++)
            cin>>r[i]>>c[i];



        int rr=-1,cc=-1,g=-1;
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
              if(r[i]==r[j])rr=r[i];
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
              if(c[i]==c[j])cc=c[i];
              for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
              if(((r[i]+c[i])%2)==((r[j]+c[j])%2))g=(r[i]+c[i])%2;
              //cout<<cc<<" "<<rr<<" "<<g<<endl;
            if(rr==1 && cc==1){hx=1,hy=1;}
            if(rr==1 && cc==n){hx=1,hy=n;}
            if(rr==n && cc==1){hx=n,hy=1;}
            if(rr==n && cc==n){hx=n,hy=n;}

        cin>>x>>y;
        if(hx!=-1)
        {
            if((x==hx)||(y==hy))
            cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
            continue;
        }
        if(((x%2)==(rr%2))||(((y%2)==(cc%2)))||(((x+y)%2)==g))cout<<"YES"<<endl;
           else cout<<"NO"<<endl;





    }
    return 0;
}