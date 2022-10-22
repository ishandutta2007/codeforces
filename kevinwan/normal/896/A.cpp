#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll l[mn];
string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string one="What are you doing while sending \"";
string two="\"? Are you busy? Will you send \"";
string three="\"?";
char find(int n,ll k){
    if(n==0){
        if(k>=l[0])return '.';
        return s[k];
    }
    if(k<one.size())return one[k];
    k-=one.size();
    if(k<l[n-1])return find(n-1,k);
    k-=l[n-1];
    if(k<two.size())return two[k];
    k-=two.size();
    if(k<l[n-1])return find(n-1,k);
    k-=l[n-1];
    if(k<three.size())return three[k];
    return '.';
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int q;
    cin>>q;
    l[0]=s.size();
    for(int i=1;i<mn;i++){
        l[i]=l[i-1]*2+one.size()+two.size()+three.size();
        l[i]=min(l[i],1LL<<60);
    }
    string ans;
    while(q--){
        int n;
        ll k;
        cin>>n>>k;
        k--;
        ans.push_back(find(n,k));
    }
    cout<<ans;
}