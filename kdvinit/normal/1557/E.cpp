/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

string s[9]={"Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", "Up-Right", "Done"};
bool Right, Left, Up, Down, Done;

void query(int r, int c)
{
    cout<<r<<" "<<c<<endl;
    string qu;  cin>>qu; int q;
    
    for(int i=0; i<9; i++) if(qu==s[i]) q=i;
    Right=0; Left=0; Up=0; Down=0, Done=0;
    
    if(q==8) Done=1;
    if(q==0 || q==4 || q==7) Right=1;
    if(q==1 || q==5 || q==6) Left=1;
    if(q==2 || q==6 || q==7) Up=1;
    if(q==3 || q==4 || q==5) Down=1;
}

void solve()
{
    int r=1, c=1;

    query(1, 8);
    if(Done) return;

    while(1)
    {
        if(c!=1)
        {
            query(r, c);
            if(Done) return;
            if(Down) { r++; continue; }
            c=1;
        }

        query(r, c);
        if(Done) return;
        if(Down) { r++; continue; }

        for(int i=2; i<=8; i++)
        {
            query(r, i);  c=i;
            if(Done) return;
            if(Down) break;
            if(Up && i!=1) i=0;
        }
        r++;
    }
    
    cout<<"Could not catch!"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}