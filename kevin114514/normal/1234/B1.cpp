#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int N,K;
    cin>>N>>K;
    while(N--)
    {
        int x;
        cin>>x;
        if(find(v.begin(),v.end(),x)!=v.end())
            continue;
        v.push_back(x);
        if(v.size()>K)
            v.erase(v.begin());
    }
    cout<<v.size()<<endl;
    for(int i=(int)v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
    return 0;;
}