#include<bits/stdc++.h>
using namespace std;
int tab1[1005];
int tab2[1005];
int tab3[1005];
void solve()
{
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
        cin>>tab1[x];
    for(int x=0;x<a;x++)
        cin>>tab2[x];
    for(int x=0;x<a;x++)
        cin>>tab3[x];
    int last=-1;
    for(int x=0;x<a-1;x++)
    {
        if(tab1[x]!=last)
        {
            cout<<tab1[x]<<" ";
            last=tab1[x];
        }
        else
        {
            cout<<tab2[x]<<" ";
            last=tab2[x];
        }
    }
    if(tab1[a-1]!=tab1[0] && tab1[a-1]!=last)
        cout<<tab1[a-1];
    else if(tab2[a-1]!=tab1[0] && tab2[a-1]!=last)
        cout<<tab2[a-1];
    else
        cout<<tab3[a-1];
    cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}