/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int len;
char ans[5001];
int n;

bool check_pal(char a[], int lp)
{
    int pos=1;
    for(int i=0;i<lp;i++)
    {
        if(a[i]!=a[lp-1-i]) pos=0;
    }
    return pos;
}

void check(char s[], int l, int r)
{
    int ln2=r-l+1;
    if(len>=ln2) return;

    char tmp[ln2];
    int cnt=0;
    for(int i=l;i<=r;i++) tmp[cnt++]=s[i];

    if(check_pal(tmp,ln2))
    {
        len=ln2;
        for(int i=0;i<ln2;i++) ans[i]=tmp[i];
    }

}

void solve()
{
    string s;
    cin>>s;

    n=s.size();
    len=0;

    char a[n];
    for(int i=0;i<n;i++) a[i]=s[i];

    int strt=0, nd=n-1;
    while(strt<=nd && a[strt]==a[nd]) { strt++; nd--; }

    if(strt>nd) { cout<<s<<endl; return; }

    for(int i=strt;i<=nd;i++)
    {
        check(a,strt,i);
        check(a,i,nd);
    }

    for(int i=0;i<strt;i++) cout<<a[i];
    for(int i=0;i<len;i++) cout<<ans[i];
    for(int i=nd+1;i<n;i++) cout<<a[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}