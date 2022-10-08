//Dawid to ziomal

#include <bits/stdc++.h>
using namespace std;
#define ll long long
map <string,priority_queue<ll>> M;
deque<string>D;



int main()
{
    ll k,n;
    cin>>k; //ilosc stringow
    cin>>n; //dl stringa
    ll sum=0;
    ll KandydatNaSrodek=0;
    
    for(int i=0;i<k;i++)
    {
        string s;
        cin>>s;
        int a;
        cin>>a;
        M[s].push(a);
    }

    string tmp;
    for(auto& m:M)
    {
        tmp=m.first;
        reverse(tmp.begin(), tmp.end());
        
       if(m.first==tmp) //jak aktualnie sprawdzana jest palindromem, to siedzi w tym samym worku
       {
           priority_queue<ll> &kolejka =M[m.first];
           while (kolejka.size()>1 and kolejka.top() > 0) //jak jest dodatnie i cos tam siedzi to paruje
           {
                ll x=kolejka.top(); kolejka.pop();
                ll y=kolejka.top(); kolejka.pop();
               
               if(x + y > 0) sum += x + y;
               
               if(y <= 0)
               {
                   if(x + y <= 0)
                   {
                       KandydatNaSrodek = max(KandydatNaSrodek, x);
                   }
                   else
                   {
                       KandydatNaSrodek = max(KandydatNaSrodek, -y);
                   }
               }
           }
           if(kolejka.size()==1)//jak zostal tam jeszcze jeden
           {
               KandydatNaSrodek=max(KandydatNaSrodek,kolejka.top());
           }
       }
        else // patrze do worka odwroconej jezeli istnieje
        {
            if(M.find(tmp) == M.end()) continue;
            //cout<<"Znalazlem odwrotna do : "<<m.first<<", ktora jest : "<<find->first<<endl;
            while (!m.second.empty() and !M[tmp].empty())
            {
                ll x=m.second.top();     m.second.pop();
                ll y=M[tmp].top();          M[tmp].pop();
                //   cout<<"x to: "<<x<<", a y to: "<<y<<endl;
                
                if(x+y>0) //robie z nich palindrom i jak daje dodatnie cos to go biere
                {
                    sum+=x+y;
                }
            }
            
        }
    }
    sum+=KandydatNaSrodek;
    cout<<sum<<endl;
    return 0;
}