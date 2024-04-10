#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n,p,q,x=-1,y=-1;
  //  scanf("%d %d %d",&n,&p,&q);
    cin>>n>>p>>q;
    string s;
    cin>>s;
  //  if (p>q)
      //  swap(p,q);

   if (n%p==0)
   {
       x=n/p;
       y=0;
   }
   else
    if (n%q==0)
   {
       x=0;
       y=n/q;
   }
    else
    for (int i=1;i<10000;i++)
    {
        if ((n-(i*p))%q==0&&n>(i*p))
        {
            x=i;
            y=(n-(i*p))/q;
        }
    }

    if (x+y==-2)
    {
        cout<<-1;
        return 0;
    }
    cout<<x+y<<endl;

    while (x>0)
    {
        for (int i=0;i<p;i++)
        {
            cout<<s[0];
            s.erase(s.begin());
        }
        x--;
        cout<<endl;
    }

    while (y>0)
    {
        for (int i=0;i<q;i++)
        {cout<<s[0];
        s.erase(s.begin());
        }
        cout<<endl;
        y--;
    }
    return 0;
}