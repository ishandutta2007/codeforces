#include <iostream>
#include<algorithm>
#include<set>

using namespace std;

int w,h,n;
set<int>l1,l2,r1,r2;
multiset<int>s1,s2;

int main()
{
    cin>>w>>h>>n;
    l1.insert(1);r1.insert(w);
    l2.insert(1);r2.insert(h);
    s1.insert(w);
    s2.insert(h);
    for(int i=1;i<=n;i++)
    {
        char c;
        int x;
        cin>>c>>x;
        if(c=='V')
        {
            int a=*(--l1.upper_bound(x)),b=*(r1.lower_bound(x));
            s1.erase(s1.lower_bound(b-a+1));
            s1.insert(x-a+1);
            s1.insert(b-x);
            l1.insert(x+1);
            r1.insert(x);
        }
        else
        {
            int a=*(--l2.upper_bound(x)),b=*(r2.lower_bound(x));
            s2.erase(s2.lower_bound(b-a+1));
            s2.insert(x-a+1);
            s2.insert(b-x);
            l2.insert(x+1);
            r2.insert(x);
        }
        long long ans1=*(--s1.end()),ans2=*(--s2.end());
        cout<<ans1*ans2<<endl;
    }
}