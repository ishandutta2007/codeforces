#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009];
bool bl[200009];
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
set<int>st;
for(int i=0;i<n;i++)
{
    cin>>a[i];
    bl[i]=0;
    st.insert(a[i]);
}
for(int i=n-1;i>=0;i--)
{
    set<int>::iterator it=st.begin();
    if((*it)==a[i])
    bl[i]=true;
    st.erase(a[i]);
}
deque<int>dq;
for(int i=0;i<n;i++)
    if(bl[i])dq.push_front(a[i]);
else dq.push_back(a[i]);
for(int i=0;i<n;i++)cout<<dq[i]<<" ";
cout<<endl;

}
return 0;
}