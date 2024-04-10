#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;

vector<int>v;
void go()
{
    cout<<v[0];
    for(int i=1;i<v.size();i++)cout<<"."<<v[i];
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x==1){v.push_back(1);go();continue;}
            while(!v.empty())
            {
                int u=v.back();
                if(u==x-1)break;
                v.pop_back();
            }
            if(!v.empty())
            v[v.size()-1]++;
            else v.push_back(x);
            go();
        }

    }

    return 0;
}