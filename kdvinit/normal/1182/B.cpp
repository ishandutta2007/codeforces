/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[501][501];        //Array to store the values
int h, w;               //Height and Width
int cnt1=0;             //Number of stars

void Take_Input()
{
    //Takes input and stores 1 for star and 0 for .
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            char x; cin>>x;
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
            cnt1+=a[i][j];
        }
    }
}

bool chk_center(int i, int j)
{
    //Checks if one star in all direction atleast
    if(a[i][j]==0) return false;
    if(a[i][j+1]==0) return false;
    if(a[i+1][j]==0) return false;
    if(a[i-1][j]==0) return false;
    if(a[i][j-1]==0) return false;
    return true;
}

int cnt1_in_dir(int i,int j, int addi, int addj)        //counts the number of consecutive stars in addi, addj direction
{
    int ans=0;
    while(i>0 && j>0 && i<=h && j<=w)
    {
        if(a[i][j]==0) break;
        ans++;
        i+=addi;        //go addi steps in i
        j+=addj;        //go addj steps in j
    }
    ans--;      //For including the center
    return ans;
}


void solve()
{
    cin>>h>>w;
    Take_Input();

    int cnt_center=0, center_i, center_j;

    for(int i=2; i<h; i++)
    {
        for(int j=2; j<w; j++)
        {
            if(chk_center(i, j)==0) continue;
            cnt_center++;
            center_i = i;
            center_j = j;
        }
    }

    if(cnt_center!=1) { cout<<"NO"<<endl; return; }

    int ans = 1;
    ans += cnt1_in_dir(center_i, center_j, 0, 1);
    ans += cnt1_in_dir(center_i, center_j, 1, 0);
    ans += cnt1_in_dir(center_i, center_j, 0, -1);
    ans += cnt1_in_dir(center_i, center_j, -1, 0);

    if(ans==cnt1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}