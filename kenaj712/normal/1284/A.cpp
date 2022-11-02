#include<bits/stdc++.h>
using namespace std;
string tab1[1000005];
string tab2[1000005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b;
    cin>>a>>b;
    for(int x=0;x<a;x++)
        cin>>tab1[x];
    for(int x=0;x<b;x++)
        cin>>tab2[x];
    int t;
    cin>>t;
    int c,d;
    while(t--)
    {
        cin>>c;
        c--;
        cout<<tab1[c%a]+tab2[c%b]<<'\n';
    }
    return 0;
}