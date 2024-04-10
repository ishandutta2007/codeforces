#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[100009],x;
int main()
{
ios::sync_with_stdio(0);
int n,q;
multiset<int>st;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>x;
    a[x]++;
}
for(int i=1;i<=100000;i++)st.insert(a[i]);
cin>>q;
char c;
for(int i=0;i<q;i++)
{cin>>c>>x;
st.erase(st.find(a[x]));
if(c=='+')a[x]++;else a[x]--;
st.insert(a[x]);

multiset<int>::iterator it=st.end();
    it--;
    int u=(*it);
    it--;
    int v=(*it);
    it--;
    int z=(*it);
   // cout<<u<<" "<<v<<" "<<z<<endl;
 if(u>=8){cout<<"YES\n";continue;}
 if(u>=6&&v>=2){cout<<"YES\n";continue;}
 if(u>=4&&v>=2&&z>=2){cout<<"YES\n";continue;}
if(u>=4&&v>=4){cout<<"YES\n";continue;}
 cout<<"NO\n";
}    return 0;
}