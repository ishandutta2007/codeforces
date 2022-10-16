#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> V;
    int x;
    char tmp;
    while(cin>>x)
    {
        cin>>tmp;
        V.push_back(x);
    }
    sort(V.begin(),V.end());
    for(int i=0;i<(int)(V.size());i++)
    {
        if(i)
            cout<<"+";
        cout<<V[i];
    }
    return 0;
}