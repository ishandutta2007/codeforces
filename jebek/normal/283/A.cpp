#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=200000+100;

ll n,t,a,x;
long double sum;
vector<long long>v,v2;

int main()
{
    cout.precision(8);
    cin>>n;
    v.push_back(0);
    v2.push_back(0);
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a>>x;
            v2[a-1]+=x;
            sum+=a*x;
            cout<<sum/(v.size())<<endl;
        }
        else if(t==2)
        {
            cin>>x;
            v.push_back(x);
            v2.push_back(0);
            sum+=x;
            cout<<sum/v.size()<<endl;
        }
        else
        {
            sum-=v[v.size()-1]+v2[v2.size()-1];
            v2[v2.size()-2]+=v2[v2.size()-1];
            v.pop_back();
            v2.pop_back();
            cout<<sum/v.size()<<endl;
        }
    }
}