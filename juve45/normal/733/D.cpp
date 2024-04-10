#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>, int> m;
int cnt=0;
priority_queue<pair<int, int> > v[300010];
int x1, x2;
int ans, ansmax, n, a, b, c;

void ins(int a, int b, int c, int i)
{
   if(m.find({a, b}) != m.end())
    {
        int ok=m[{a, b}];
        v[ok].push({c, i});
    }
    else{
     m[{a, b}] = cnt++;
     v[cnt-1].push({c, i});
}

}

int main()
{

   // freopen("in.txt", "r", stdin);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b>>c;
        if(a>b) swap(a, b);
        if(a>c) swap(a, c);
        if(b>c) swap(b, c);
        ins(a, b, c, i);
        ins(b, c, a, i);
        ins(a, c, b, i);
    }
    ansmax=0;


    for(map<pair<int, int>, int> :: iterator it = m.begin(); it!=m.end();it++)
    {
        pair<int, int> o=it->first;
        int ok=it->second;

        int ans=v[ok].top().first;
        int g=v[ok].top().second;
        int g2=-1;
        v[ok].pop();

        while(!v[ok].empty() && g==v[ok].top().second)
            v[ok].pop();

        if(!v[ok].empty())
        {
            ans+=v[ok].top().first;
            g2=v[ok].top().second;
        }
        ans=min(ans, o.first);
        ans=min(ans, o.second);
        if(ans>ansmax)
        {
            ansmax=ans;
            x1=g;
            x2=g2;
        }
    }
    if(x2==-1)
    cout<<"1\n"<<x1<<'\n';
    else cout<<"2\n"<<x1<<' '<<x2<<'\n';


    return 0;
}