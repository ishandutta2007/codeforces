#include <bits\stdc++.h>

using namespace std;
vector<int> a;

int main()
{
  int n;  scanf("%d",&n);
//    cout << "Hello world!" << endl;
int x;
for (int i=0;i<n;i++)
{
    scanf("%d",&x);
    a.push_back(x);
}
    sort(a.begin(),a.end());

    int ans=0,l=0;

    while (l<n)
    {
        ans++;
        int num=0;

    for (int i=0;i<n;i++)
    {
        if (a[i]>=num)
        {

            l++;
            num++;
            
            a[i]=-1;
        }
    }
  
    }
    cout<<ans;
    return 0;
}