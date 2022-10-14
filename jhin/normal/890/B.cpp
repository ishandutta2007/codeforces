#include <bits/stdc++.h>

using namespace std;
int n,a[200004],b[200004],ans=200005;
int main()
{cin>>n;
for(int i=0;i<200001;i++)b[i]=-1;
    for(int i=0;i<n;i++){cin>>a[i];b[a[i]]=i;}
    for(int i=0;i<=200000;i++)if(b[i]!=-1)ans=min(ans,b[i]);
        cout<<a[ans];
    return 0;
}