#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1009],ans[1009];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
set<int>st;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    st.insert(i);
}
if(n==1){cout<<-1<<endl;continue;}
for(int i=1;i<n;i++)
{
    set<int>::iterator it=st.begin();
    if((*it)!=a[i]){ans[i]=(*it);st.erase(it);continue;}
    it++;
    ans[i]=(*it);st.erase(it);
}
ans[n]=(*st.begin());
if(ans[n]==a[n])swap(ans[n],ans[n-1]);
for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
cout<<endl;


}

return 0;
}