#include<bits/stdc++.h>
using namespace std;
int tab[1000005];
int suf[1000005];
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    string a;
    cin>>a;
    int act=0;
    for(int x=0;x<a.size();x++)
    {
        if(a[x]=='1')
            act++;
        else
            act--;
        tab[x]=act;
    }
    suf[a.size()-1]=tab[a.size()-1];
    suf[a.size()]=suf[a.size()-1];
    for(int x=a.size()-2;x>=0;x--)
        suf[x]=min(suf[x+1],tab[x]);
    act=0;
    for(int x=0;x<a.size();x++)
    {
        if(a[x]=='1')
            act++;
        else
            act--;
        if(a[x]=='0')
            v.push_back(0);
        else
        {
            if(-act+suf[x+1]>=0)
                v.push_back(0);
            else
                v.push_back(1);
        }
    }
    for(auto x:v)
        cout<<x;
	return 0;
}