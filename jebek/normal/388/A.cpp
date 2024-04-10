#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
long long ans,MAX=1,t[200],a,n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        t[a]++;
    }
    for(int i=0;i<=100;i++)
    {
        ans+=t[i];
        MAX=max(MAX,(ans+i)/(i+1));
    }
    cout<<MAX<<endl;
}