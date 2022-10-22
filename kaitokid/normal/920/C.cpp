#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int MOD=1e9 +7;
int a[200009];
vector<pair<int,int> >p;
int main() {
ios::sync_with_stdio(0);
int n;
string s;
cin>>n;
for(int i=0;i<n;i++)cin>>a[i];
cin>>s;
int d=0;
p.push_back(make_pair(a[0],0));
for(int i=1;i<n;i++)
{
if(s[i-1]=='0')d++;
p.push_back(make_pair(a[i],d));
}
sort(p.begin(),p.end());
for(int i=1;i<n;i++)
{
if(p[i].second<p[i-1].second){cout<<"NO";return 0;}


}
cout<<"YES";
 return 0; }