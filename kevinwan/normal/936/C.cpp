#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
typedef long long ll;
const int mn=4e5+10;
vector<int>rep;
string s,t,u;
int n;
void hail(int d,int x){
    rep.push_back(n-x);
    rep.push_back(x-d);
    rep.push_back(n);
    u=s;
    for(int i=0;i<n-x;i++)u[d+i]=s[i+x];
    for(int i=0;i+d<x;i++)u[d+n-x+i]=s[d+i];
    s=u;
    reverse(s.begin(),s.begin()+d);
}
int cnt[256];
void die(){
    printf("-1");
    exit(0);
}
string o;
int main(){
    cin>>n>>s>>t;
    u.resize(n);
    for(char c:s)cnt[c]++;
    for(char c:t)cnt[c]--;
    for(int i=0;i<256;i++)if(cnt[i])die();
    o.push_back(t[n/2]);
    for(int i=1;i<=n;i++){
        if(n/2-i>=0)o.push_back(t[n/2-i]);
        if(n/2+i<n)o.push_back(t[n/2+i]);
    }
    for(int i=0;i<n;i++){
        int tar=0;
        for(int j=i;j<n;j++)if(s[j]==o[i])tar=j;
        hail(i,tar);
    }
    if(s!=t)rep.push_back(n);
    printf("%d\n",rep.size());
    for(int x:rep)printf("%d ",x);
}