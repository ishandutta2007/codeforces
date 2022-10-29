#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m,k,i,j,xa,ya,xb,yb,ans=-1,v[1001][1001]={0},x,y;
int main()
{
    io
    string s[1001];
    cin>>n>>m>>k;
    for(i=0;i<n;++i)
    cin>>s[i];
    cin>>xa>>ya>>xb>>yb;
    xa--,ya--,xb--,yb--;
    if(xa==xb and ya==yb) {cout<<0;return 0;}
    set < pair < int , pair < pll , pll > > > st;
    st.insert({1,{{0,k},{xa,ya}}});
    st.insert({1,{{1,k},{xa,ya}}});
    st.insert({1,{{2,k},{xa,ya}}});
    st.insert({1,{{3,k},{xa,ya}}});
    while(!st.empty())
    {
        pair < int , pair < pll , pll > > t=*st.begin(),tt;
        st.erase(st.begin());
        x=t.y.y.x;
        y=t.y.y.y;
        v[x][y]=1;
        if(x==xb && y==yb) {ans=t.x;break;}
        if(x<n-1 && s[x+1][y]=='.' && !v[x+1][y])
        {
            tt=t;
            if(t.y.x.x==1)
            {
                if(t.y.x.y>0)
                {
                    tt.y.x.y--;
                    tt.y.y.x++;
                    st.insert(tt);
                }
                else
                {
                    tt.y.x.y=k-1;
                    tt.x++;
                    tt.y.y.x++;
                    st.insert(tt);
                }
            }
            else
            {
                tt.y.x.x=1;
                tt.y.x.y=k-1;
                tt.x++;
                tt.y.y.x++;
                st.insert(tt);
            }
        }
        if(x && s[x-1][y]=='.' && !v[x-1][y])
        {
            tt=t;
            if(t.y.x.x==3)
            {
                if(t.y.x.y>0)
                {
                    tt.y.x.y--;
                    tt.y.y.x--;
                    st.insert(tt);
                }
                else
                {
                    tt.y.x.y=k-1;
                    tt.x++;
                    tt.y.y.x--;
                    st.insert(tt);
                }
            }
            else
            {
                tt.y.x.x=3;
                tt.y.x.y=k-1;
                tt.x++;
                tt.y.y.x--;
                st.insert(tt);
            }
        }
        if(y<m-1 && s[x][y+1]=='.' && !v[x][y+1])
        {
            tt=t;
            if(t.y.x.x==0)
            {
                if(t.y.x.y>0)
                {
                    tt.y.x.y--;
                    tt.y.y.y++;
                    st.insert(tt);
                }
                else
                {
                    tt.y.x.y=k-1;
                    tt.x++;
                    tt.y.y.y++;
                    st.insert(tt);
                }
            }
            else
            {
                tt.y.x.x=0;
                tt.y.x.y=k-1;
                tt.x++;
                tt.y.y.y++;
                st.insert(tt);
            }
        }
        if(y && s[x][y-1]=='.' && !v[x][y-1])
        {
            tt=t;
            if(t.y.x.x==2)
            {
                if(t.y.x.y>0)
                {
                    tt.y.x.y--;
                    tt.y.y.y--;
                    st.insert(tt);
                }
                else
                {
                    tt.y.x.y=k-1;
                    tt.x++;
                    tt.y.y.y--;
                    st.insert(tt);
                }
            }
            else
            {
                tt.y.x.x=2;
                tt.y.x.y=k-1;
                tt.x++;
                tt.y.y.y--;
                st.insert(tt);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}