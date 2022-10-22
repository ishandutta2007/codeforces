#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
ll n,k;
set<char>st;
int main() 
{ 
ios::sync_with_stdio(0);
cin>>n>>k;
string s;
cin>>s;

for(int i=0;i<n;i++)
st.insert(s[i]);
if(k>n){
cout<<s;
for(int i=n;i<k;i++)cout<<(*(st.begin()));
return 0;


}
int i=k-1;
while(true)
{
set<char>::iterator it=st.lower_bound(s[i]);
it++;
if(it==st.end()){s[i]=(*(st.begin()));i--;continue;}
s[i]=*it;
break;



}
for(int j=0;j<k;j++)cout<<s[j];
return 0 ;}