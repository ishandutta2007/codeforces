#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bit[100009][2],n,fr[100009][2];
int cal(int x,int id)
{
    int res=0;
    while(x>0)
    {
        res+=bit[x][id];
        x-=(x&(-x));
    }
    return res;
}
void add(int x,int id,int val)
{
    while(x<=n)
    {
        bit[x][id]+=val;
        x+=(x&(-x));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>n>>q;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            fr[x][0]++;
            if(fr[x][0]==1)add(x,0,1);
            fr[y][1]++;
            if(fr[y][1]==1)add(y,1,1);
            continue;
        }

        if(t==2)
        {
            int x,y;
            cin>>x>>y;
            fr[x][0]--;
            if(fr[x][0]==0)add(x,0,-1);
            fr[y][1]--;
            if(fr[y][1]==0)add(y,1,-1);
            continue;
        }
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int g=cal(c,0)-cal(a-1,0),h=cal(d,1)-cal(b-1,1);
        if((g==c-a+1)||(h==d-b+1))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}