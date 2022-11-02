#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005][30];
int a;
string tab;
int conv(char d)
{
    return int(d)-97;
}
int rek(int c,int d,int e)
{
    if(dp[c][d][e]!=0)
        return dp[c][d][e];
    if(c==d)
    {
        if(conv(tab[c])==e)
            return 1;
        return 2;
    }
    if(d<c)
        return 1;
    int mini=1e9;
    for(int x=c;x<=d;x++)
    {
        if(conv(tab[x])==e)
            mini=min(mini,rek(c,x-1,e)+rek(x+1,d,e)-1);
        else
            mini=min(mini,rek(c,x-1,conv(tab[x]))+rek(x+1,d,conv(tab[x])));
    }
    dp[c][d][e]=mini;
    return mini;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>a;
    cin>>tab;
    int mini=1e9;
    for(int x=0;x<26;x++)
        mini=min(mini,rek(0,a-1,x));
    cout<<mini;
	return 0;
}