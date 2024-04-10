#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ans[109][109];
int u,v,g;
void go()
{

    for(int i=0;i<u;i++)
        for(int j=0;j<v;j++)ans[i][j]='.';
    for(int j=0;j<v;j+=2)
    {
        for(int i=0;i<u;i++)
        {
            if(g==0)break;
            if((i + ((j/2)%2) )%2)ans[i][j]=ans[i][j+1]='b';
            else ans[i][j]=ans[i][j+1]='a';
            g--;
        }
    }
    for(int i=0;i<u;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(ans[i][j]!='.')continue;
            if((((i/2)%2) +j)%2)ans[i][j]=ans[i+1][j]='d';
            else ans[i][j]=ans[i+1][j]='c';

        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        u=n,v=m,g=k;
        if(m==1 &&(k>0)){cout<<"NO\n";continue;}

        if((n%2)==0)
        {

            if((k%2)!=0){cout<<"NO\n";continue;}
            m-=(m%2);
            int r=(n*m)/2;
            if(r<k) cout<<"NO\n";
            else {cout<<"YES\n";go();
            for(int i=0;i<u;i++)
            {
                for(int j=0;j<v;j++)cout<<ans[i][j];
                cout<<endl;
            }
            }
            continue;
        }

            k=(n*m)/2-k;
            g=k;
            swap(u,v);
            if(n==1 &&(k>0)){cout<<"NO\n";continue;}
            if((k%2)!=0){cout<<"NO\n";continue;}
            n-=(n%2);
            int r=(n*m)/2;
            if(r<k) cout<<"NO\n";
            else {cout<<"YES\n";go();
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<u;j++)cout<<ans[j][i];
                cout<<endl;
            }
            }
            continue;

    }
    return 0;
}