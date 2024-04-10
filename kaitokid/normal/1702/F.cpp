#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    multiset <int> a,b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while((x%2)==0)x/=2;
        a.insert(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while((x%2)==0)x/=2;
        b.insert(x);
    }
    bool ans=true;
    set<int> ::iterator it1,it2;
    while(!a.empty())
    {
        it1=a.end(),it2=b.end();
        it1--,it2--;
        int x=(*it1),y=(*it2);
        if(x==y){a.erase(it1);b.erase(it2);continue;}
        if(x>y){ans=false;break;}
        b.erase(it2);
        b.insert((y/2));
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
return 0;
}