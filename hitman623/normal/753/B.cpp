#include <bits/stdc++.h>

using namespace std;

int main()
{   int aa[10],bb[10],i,c[4],l=0,a,b;
    for(i=0;i<10;++i)
    {cout<<i<<i<<i<<i<<endl;fflush(stdout);
    cin>>aa[i]>>bb[i];
    if(aa[i] || bb[i]) c[l++]=i;
    if(l==4) break;
    }
    cout<<c[0]<<c[1]<<c[2]<<c[3]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[0]<<c[1]<<c[3]<<c[2]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[0]<<c[2]<<c[1]<<c[3]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[0]<<c[2]<<c[3]<<c[1]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[0]<<c[3]<<c[1]<<c[2]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[0]<<c[3]<<c[2]<<c[1]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[1]<<c[0]<<c[2]<<c[3]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[1]<<c[0]<<c[3]<<c[2]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[1]<<c[2]<<c[0]<<c[3]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[1]<<c[2]<<c[3]<<c[0]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[1]<<c[3]<<c[0]<<c[2]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[1]<<c[3]<<c[2]<<c[0]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[2]<<c[0]<<c[3]<<c[1]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[2]<<c[0]<<c[1]<<c[3]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[2]<<c[1]<<c[0]<<c[3]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[2]<<c[1]<<c[3]<<c[0]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[2]<<c[3]<<c[1]<<c[0]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[2]<<c[3]<<c[0]<<c[1]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[3]<<c[0]<<c[1]<<c[2]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[3]<<c[0]<<c[2]<<c[1]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[3]<<c[1]<<c[0]<<c[2]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[3]<<c[1]<<c[2]<<c[0]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[3]<<c[2]<<c[0]<<c[1]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    cout<<c[3]<<c[2]<<c[1]<<c[0]<<endl;cin>>a>>b;fflush(stdout); if(a==4) {exit(0);}
    return 0;
}