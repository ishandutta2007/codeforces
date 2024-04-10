#include<bits/stdc++.h>
using namespace std;
bool ok(vector<int> &v)
{
    int N=v.size();
    for(int i=0;i<N;i++)
        if(v[(i+1)%N]!=(v[i]+1)%N)
            return false;
    return true;
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        vector<int> v;
        int M;
        cin>>M;
        while(M--)
        {
            int x;
            cin>>x;
            x--;
            v.push_back(x);
        }
        bool ok1=false;
        ok1|=ok(v);
        reverse(v.begin(),v.end());
        ok1|=ok(v);
        puts(ok1?"YES":"NO");
    }
    return 0;
}