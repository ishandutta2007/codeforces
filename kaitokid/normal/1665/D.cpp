#include<bits/stdc++.h>
using namespace std;
int fr[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
    int x=0;

    for(int i=0;i<29;i++)
    {
        int u=(1<<(i+1));
        cout<<"? "<<u-x<<" "<<2*u-x<<endl;
        fflush(stdout);
        int r;
        cin>>r;
        if(r==u)continue;
        x+=(1<<i);

    }
    int u=(1<<29),v=(1<<30);
    cout<<"? "<<u-x<<" "<<u+v-x<<endl;
    fflush(stdout);
    int r;
    cin>>r;
    if(r==v)x|=u;
   cout<<"! "<<x<<endl;
   fflush(stdout);
   /* int q=0;


    while(q<30 && x<u)
    {
        q++;
        cout<<"? "<<u-x<<" "<<u+v-x<<endl;
        fflush(stdout);
        int r;
        cin>>r;
        if(r==v)break;
        x+=r;
    }*/
    }
    return 0;
}