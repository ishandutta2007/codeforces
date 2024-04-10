#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=5e3+10;
int lo[mn],hi[mn];
ll plo[mn],phi[mn];
ll ev[mn][mn];
int main()
{
    string s;
    cin>>s;
    int st=0,i;
    for(i=2;i<s.size();i+=2){
        if(s[i-1]=='+'){
            for(int j=st;j<i;j+=2)lo[j]=st,hi[j]=i-2;
            plo[st]=s[st]-'0';
            for(int j=st+2;j<i;j+=2)plo[j]=plo[j-2]*(s[j]-'0');
            phi[i-2]=s[i-2]-'0';
            for(int j=i-4;j>=st;j-=2)phi[j]=phi[j+2]*(s[j]-'0');
            st=i;
        }
    }
    for(int j=st;j<i;j+=2)lo[j]=st,hi[j]=i-2;
    plo[st]=s[st]-'0';
    for(int j=st+2;j<i;j+=2)plo[j]=plo[j-2]*(s[j]-'0');
    phi[i-2]=s[i-2]-'0';
    for(int j=i-4;j>=st;j-=2)phi[j]=phi[j+2]*(s[j]-'0');
    for(i=0;i<s.size();i+=2){
        ll cum=0,ad=1;
        ev[i][i]=s[i]-'0';
        ad=ev[i][i];
        for(int j=i+2;j<s.size();j+=2){
            if(s[j-1]=='*')ad*=s[j]-'0';
            else cum+=ad,ad=s[j]-'0';
            ev[i][j]=cum+ad;
        }
    }
    ll ans=0;
    for(int i=0;i<s.size();i+=2){
        for(int j=i;j<s.size();j+=2){
            ll ini=ev[i][j];
            if(lo[i]!=i)ini*=plo[i-2];
            if(hi[j]!=j)ini*=phi[j+2];
            if(lo[i]-2>=0)ini+=ev[0][lo[i]-2];
            if(hi[j]+2<s.size())ini+=ev[hi[j]+2][s.size()-1];
            ans=max(ans,ini);
        }
    }
    cout<<ans;
}