#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> o;

int main()
{
    pair <int,int> a[110];
    int n,k,ans=0;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        if (k>=a[i].first) {
        ans++;
        k-=a[i].first;
        o.push_back(a[i].second);
        }
        else break;
    }
    cout<<ans<<endl;
    if (ans>0) cout<<o[0];
    for (size_t i=1;i<ans;i++)
    cout<<" "<<o[i];
  return 0;
}