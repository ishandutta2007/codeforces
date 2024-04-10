#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,k;
set<ll>a;
string s;
int main()
{
 ios::sync_with_stdio(0);
    cin>>n>>k;
cin>>s;
for(int i=0;i<n-1;i++)if(s[i]==s[i+1]){a.insert(i);a.insert(i+1);}
if(s[0]==s[n-1]){a.insert(0);a.insert(n-1);}
for(int i=0;i<n;i++)
{
    if(a.empty()){

            if(k%2==0)cout<<s[i];else{if(s[i]=='W')cout<<"B";else cout<<"W";}

            continue;}
    ll l=abs(i-*(a.begin()));
    l=min(l,n-l);
    set<ll>::iterator it=a.lower_bound(i);
    ll  q;
    if(it!=a.end()){ll q=abs((*it)-i);l=min(q,l);l=min(l,n-q);}
   if(it!=a.begin()) it--;
    if(it!=a.end()){ll q=abs((*it)-i);l=min(q,l);l=min(l,n-q);}
    it=a.end();
    it--;
    if(it!=a.end()){ll q=abs((*it)-i);l=min(q,l);l=min(l,n-q);}
    if(k>=l){if(l%2==0)cout<<s[i];else{if(s[i]=='W')cout<<"B";else cout<<"W";}continue;}
    if(k%2==0)cout<<s[i];else{if(s[i]=='W')cout<<"B";else cout<<"W";}
}
    return 0;
}