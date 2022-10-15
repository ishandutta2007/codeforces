/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string Fillipino = "po";
    string Japanese1 = "desu";
    string Japanese2 = "masu";
    string Korean = "mnida";

    string s;
    cin>>s;

    int n = s.size();

    if(s.substr(n-2, 2) == Fillipino) { cout<<"FILIPINO"<<endl; return; }
    if(s.substr(n-4, 4) == Japanese1) { cout<<"JAPANESE"<<endl; return; }
    if(s.substr(n-4, 4) == Japanese2) { cout<<"JAPANESE"<<endl; return; }
    if(s.substr(n-5, 5) == Korean) { cout<<"KOREAN"<<endl; return; }


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}